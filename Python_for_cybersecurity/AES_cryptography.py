from Crypto.Cipher import AES
from Crypto.Util.Padding import pad, unpad
from Crypto.Random import get_random_bytes

def encrypt_content(plain_text: bytes, Key: bytes) -> bytes:
    iv = get_random_bytes(16)
    cipher = AES.new(Key, AES.MODE_CBC, iv)
    padded_data = pad(plain_text, AES.block_size)
    encrypted_data = cipher.encrypt(padded_data)
    return iv + encrypted_data

def decrypt_content(encrypted_data: bytes, Key: bytes) -> bytes:
    iv = encrypted_data[:16]
    encrypted_data = encrypted_data[16:]
    cipher = AES.new(Key, AES.MODE_CBC, iv)
    padded_data = cipher.decrypt(encrypted_data)
    plain_text = unpad(padded_data, AES.block_size)
    return plain_text

def read_file(file_path: str) -> bytes:
    with open(file_path, 'rb') as f:
        return f.read()

def write_file(file_path: str, data: bytes):
    with open(file_path, 'wb') as f:
        f.write(data)

def main():
    Key = b'This is a Key123'  # Key should be 16, 24, or 32 bytes long for AES
    original_content = read_file('example.txt')
    print("Original content: ")
    print(original_content.decode())

    encrypted_content = encrypt_content(original_content, Key)
    print("\nEncrypted content (hex):")
    print(encrypted_content.hex())

    decrypted_content = decrypt_content(encrypted_content, Key)
    print('\nDecrypted content: ')
    print(decrypted_content.decode())

    write_file('encrypted_example.bin', encrypted_content)
    write_file('decrypted_example.txt', decrypted_content)

if __name__ == "__main__":
    main()