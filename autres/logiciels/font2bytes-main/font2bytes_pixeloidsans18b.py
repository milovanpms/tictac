from PIL import Image, ImageDraw, ImageFont
from numpy import asarray, ceil, array, sum, concatenate
import os

# Configuration
filename = 'PixeloidSans18b'           # <----- select new font name
fontname = 'PixeloidSans.ttf'         # <----- specify the font you intend to use. Place any font into the fonts folder
height = 22                           # <----- new font height
default_width = 12                    # <----- default font width

# Special widths for larger or thinner characters
special_widths = {
   #<ascii>: <width>,
    32: 6,   # 'space'
    39: 8,   # "'"
    46: 4,   # "."
    77: 16,  # 'M'
    78: 16,  # 'N'
    87: 16,  # 'W'
    102: 8,  # 'f'
    105: 6,  # 'i'
    106: 8,  # 'j'
    108: 6,  # 'l'
    109: 16, # 'm'
    110: 13, # 'n'
    #115: 12,  # 's'
    116: 10,  # 't'
    119: 16, # 'w'
}

THRESHOLD = 120                      # <----- image intensity threshold for binary conversion. It changes the contrast of the final font (default: 120)
font_offset = 4  # recommended to be at least 4
binary_byte = array([128, 64, 32, 16, 8, 4, 2, 1])

# Assurez-vous que les dossiers nécessaires existent
os.makedirs('./tmp', exist_ok=True)
os.makedirs('./output', exist_ok=True)
os.makedirs('./fonts', exist_ok=True)

def get_char_width(ASCII):
    """Retourne la largeur pour un caractère spécifique"""
    return special_widths.get(ASCII, default_width)

def createTMPimage(ASCII):
    """Crée une image temporaire pour un caractère ASCII"""
    # Create a font object
    font = ImageFont.truetype(f"./fonts/{fontname}", height - font_offset)
    
    # Calculate character dimensions
    char_width = int(font.getlength(chr(ASCII)))
    
    # Get width for this character
    img_width = get_char_width(ASCII)
    
    # Create an image with special width if needed
    image = Image.new('RGB', (img_width, height), color=(0, 0, 0))
    draw = ImageDraw.Draw(image)
    
    # Center the character
    x_pos = (img_width - char_width) // 2
    draw.text((x_pos, 0), chr(ASCII), font=font, fill=(255, 255, 255))
    
    # Save the temporary image
    image.save(f'./tmp/{ASCII}.bmp')

def readImage2Binary(ASCII):
    """Lit une image et la convertit en données binaires"""
    image = Image.open(f'./tmp/{ASCII}.bmp')
    data = asarray(image)
    binary_map = data[:, :, 0]
    return binary_map

def convertMap2Hex(binary_map, ASCII):
    """Convertit une carte binaire en valeurs hexadécimales"""
    hex_map = []
    
    # Get width for this character
    char_width = get_char_width(ASCII)
    
    for line in range(binary_map.shape[0]):
        for bit_chunks in range(int(ceil(char_width/8))):
            tmp = binary_map[line][bit_chunks*8:(min((bit_chunks+1)*8, char_width))]
            tmp = array(list(map(lambda x: int(x > THRESHOLD), tmp)))
            tmp = concatenate((tmp, array([0] * (8 - len(tmp)))))  # padding with zeros
            binary_value = int(sum(tmp * binary_byte))
            hex_map.append(f"{binary_value:#0{4}x}")
    return hex_map

def write_file_intro(f):
    """Écrit l'introduction du fichier de police"""
    f.write('/* Includes ------------------------------------------------------------------*/\n')
    f.write('#include "fonts.h"\n')
    f.write(f'const uint8_t {filename}_Table [] = \n')
    f.write('{\n')

def write_width_table(f):
    """Écrit le tableau des largeurs de caractères"""
    f.write(f'const uint8_t {filename}_Widths [] = \n')
    f.write('{\n\t')
    for ASCII in range(32, 127):
        f.write(f'{get_char_width(ASCII)}, ')
        if (ASCII - 31) % 16 == 0:
            f.write('\n\t')
    f.write('\n};\n\n')

def write_file_closure(f):
    """Écrit la fermeture du fichier de police"""
    f.write('};\n\n')
    # Write width table
    write_width_table(f)
    # Write font struct
    f.write(f'sFONT {filename} = {{\n')
    f.write(f'\t{filename}_Table,\n')
    f.write(f'\t{filename}_Widths,  /* Character width table */\n')
    f.write(f'\t{default_width}, /* Default Width */\n')
    f.write(f'\t{height}, /* Height */\n')
    f.write('};\n\n')

def write_letter(f, ASCII, hex_map):
    """Écrit les données d'un caractère dans le fichier"""
    char_width = get_char_width(ASCII)
    
    f.write(f'\t// ASCII: {ASCII} "{chr(ASCII)}" ({char_width} pixels wide)\n')
    count = 0
    f.write('\t')
    for item in hex_map:
        f.write(f'{item}, ')
        count += 1
        if count == 3:
            count = 0
            f.write('\n\t')
    f.write('\n')

if __name__ == "__main__":
    with open(f'./output/{filename}.c', 'w') as f:
        write_file_intro(f)
        for ASCII in range(32, 127):
            print(f'working on ASCII: {ASCII}: {chr(ASCII)}')
            createTMPimage(ASCII)
            binary_map = readImage2Binary(ASCII)
            hex_map = convertMap2Hex(binary_map, ASCII)
            write_letter(f, ASCII, hex_map)
        write_file_closure(f)
    
    print(f"Police générée avec succès dans ./output/{filename}.c")
    print("N'oubliez pas de mettre à jour votre structure sFONT dans fonts.h!")