import zipfile

input_file = 'input.txt'
output_file = 'compressed_file.zip'

with zipfile.ZipFile(output_file, 'w', zipfile.ZIP_DEFLATED) as zipf:
    zipf.write(input_file, arcname='input.txt')

print(f'File "{input_file}" has been compressed to "{output_file}"')
