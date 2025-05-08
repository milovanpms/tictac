import tkinter as tk
from PIL import Image, ImageTk

def show_all_chars():
    window = tk.Tk()
    window.title("Aperçu de la police")

    canvas = tk.Canvas(window, bg='black')
    canvas.pack(fill="both", expand=True)

    x_offset = 10
    y_offset = 10
    max_height = 0

    for ASCII in range(32, 127):
        img_path = f'./tmp/{ASCII}.bmp'
        try:
            img = Image.open(img_path)
            img_tk = ImageTk.PhotoImage(img)

            canvas.create_image(x_offset, y_offset, image=img_tk, anchor='nw')
            canvas.image = getattr(canvas, 'image', []) + [img_tk]  # Prevent garbage collection

            x_offset += img.width + 5
            max_height = max(max_height, img.height)

            if x_offset > 500:  # change width threshold as needed
                x_offset = 10
                y_offset += max_height + 5
                max_height = 0

        except FileNotFoundError:
            print(f"Image for ASCII {ASCII} not found.")

    window.mainloop()

if __name__ == "__main__":
    show_all_chars()
