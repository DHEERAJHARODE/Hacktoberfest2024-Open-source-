morse_code_dict = {
    'A': '.-', 'B': '-...', 'C': '-.-.', 'D': '-..', 'E': '.', 
    'F': '..-.', 'G': '--.', 'H': '....', 'I': '..', 'J': '.---', 
    'K': '-.-', 'L': '.-..', 'M': '--', 'N': '-.', 'O': '---', 
    'P': '.--.', 'Q': '--.-', 'R': '.-.', 'S': '...', 'T': '-', 
    'U': '..-', 'V': '...-', 'W': '.--', 'X': '-..-', 'Y': '-.--', 
    'Z': '--..', '1': '.----', '2': '..---', '3': '...--', 
    '4': '....-', '5': '.....', '6': '-....', '7': '--...', 
    '8': '---..', '9': '----.', '0': '-----', ' ': '/'
}

def encode_to_morse(text):
    text = text.upper()
    morse_code = ''
    for char in text:
        if char in morse_code_dict:
            morse_code += morse_code_dict[char] + ' '
    return morse_code.strip()


def decode_from_morse(morse_code):
    inverse_dict = {v: k for k, v in morse_code_dict.items()}
    decoded_text = ''
    morse_words = morse_code.split(' / ')
    
    for word in morse_words:
        morse_chars = word.split()
        for char in morse_chars:
            if char in inverse_dict:
                decoded_text += inverse_dict[char]
        decoded_text += ' '  
    
    return decoded_text.strip()


if __name__ == "__main__":
    while True:
        choice = input("Type 'encode' to convert text to Morse code or 'decode' to convert Morse code to text (or 'exit' to quit): ").strip().lower()
        
        if choice == 'encode':
            text = input("Enter text to encode: ")
            morse_code = encode_to_morse(text)
            print(f"Encoded Morse Code: {morse_code}")
        
        elif choice == 'decode':
            morse_code = input("Enter Morse code to decode (use spaces between letters and '/' for words): ")
            decoded_text = decode_from_morse(morse_code)
            print(f"Decoded Text: {decoded_text}")
        
        elif choice == 'exit':
            print("Exiting the program.")
            break
        
        else:
            print("Invalid choice. Please try again.")
