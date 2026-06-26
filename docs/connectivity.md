# 📶 Connectivity
 
## Why Bluetooth, and why HC-05
 
The watch has no internet connectivity of its own. Any exchange with the outside world (in practice, just time synchronisation) has to go through a paired smartphone or tablet running a dedicated companion app. Bluetooth is the obvious fit here: it's the one wireless link that's both standard on every phone and easy to bridge into a microcontroller's UART.
 
That's exactly what the **HC-05** module is. It's a classic Bluetooth module: from the phone's side it shows up as a normal Bluetooth device, and from the **STM32G431KB**'s side it's nothing more than a UART peripheral. There's no Bluetooth stack to implement on the MCU: the HC-05 handles all of that on its own firmware, and simply forwards whatever bytes it receives over the air onto its TX/RX pins.
 
See [Architecture documentation](./architecture.md#pin-mapping) for the physical pin mapping (`PA9`/`PA10`).

## Protocol overview
 
UART over Bluetooth is already a reliable, ordered, point-to-point byte stream. The protocol is intentionally minimal: plain ASCII text commands, one per line.

### Frame format
 
| Field          | Size      | Description                                              |
|----------------|-----------|------------------------------------------------------------|
| Command char   | `1 byte`  | Selects the action to perform (currently: `z`)             |
| Parameters     | variable  | ASCII fields specific to the command, separated by `:` and `/` |
| Terminator     | `1 byte`  | `\n` or `\r` marks the end of the message                  |

### Supported commands
 
| Command | Format                     | Effect                                              |
|---------|------------------------------|------------------------------------------------------|
| `z`     | `zHH:MM:SS;DD/MM/YYYY`        | Parses the date and time, writes them to the RTC      |

```c
// process_received_message(), case 'z':
sscanf(receive_buffer + 1, "%d:%d:%d;%d/%d/%d",
       &hours, &minutes, &seconds, &day, &month, &year);
```

> [!NOTE]
> Only one command exists today, but the `switch` on `receive_buffer[0]` is built to scale: a future phone-side feature (pulling step history, configuring an alarm, etc.) just needs one more `case`, not a redesign of the protocol.

## Reception pipeline
 
```
HC-05 (UART1 RX) ➜ handle_uart_reception() ➜ receive_buffer[64] ➜ process_received_message() ➜ RTC
```
 
`handle_uart_reception()` is **polled**, not interrupt-driven: it's called on every iteration of the `DETECTION` state in `main.c`'s main loop (see [Firmware documentation](./firmware.md)), and simply does nothing if no byte is waiting:
 
```c
while (BSP_UART_data_ready(UART1_ID)) {
    received_char = BSP_UART_getc(UART1_ID);
    BSP_UART_putc(UART2_ID, received_char);   // echoed to the debug console
    ...
}
```

Every received character is echoed onto **UART2** (the debug console, see [Architecture documentation](./architecture.md#software-peripheral-configuration)) as it comes in. This makes raw Bluetooth traffic visible live in a serial terminal; practical for debugging the phone app, at the cost of a noisier debug console.

Characters accumulate in `receive_buffer` until a `\n` or `\r` is seen, at which point the buffer is null-terminated and handed off to `process_received_message()`.

### Buffer management
 
`receive_buffer` is a fixed `64`-byte array. The write is bounds-checked (`buffer_index < BUFFER_SIZE - 1`), so there's no risk of overflowing memory. However, a message longer than 63 characters before its terminator will simply have its extra bytes dropped rather than rejected outright, since the function keeps consuming characters from UART1 either way.

## Time synchronisation with the companion app
 
After pairing the phone with the device named **"Tictac"** in the system Bluetooth settings, the companion app exposes a sync button. Pressing it sends a `z` command with the phone's current date and time, which the firmware applies to the RTC via `BSP_RTC_set_time()` / `BSP_RTC_set_date()`. From that point on the watch keeps time on its own, entirely independent of the phone; sync is a one-shot push, not a maintained connection, and can be repeated at any time by pressing the button again.

## Known Limitations
 
**One-way only.** Data only ever flows from the phone to the watch (time sync). There is no command to pull step count, distance or heart-rate history back out over Bluetooth.
 
**No acknowledgement.** The app has no way of knowing whether a `z` command actually succeeded: if `sscanf()` fails to match all six fields, `process_received_message()` does nothing, and no error is reported back over UART1.
 
**NFC was the planned second channel, never implemented.** The original specifications included NFC (via a PN532 module) for badge emulation/duplication. It never made it into the firmware. Bluetooth, documented here, is the device's only working connectivity today.
