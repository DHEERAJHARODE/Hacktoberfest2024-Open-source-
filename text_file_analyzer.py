import string
from tkinter import filedialog
import tkinter as tk

def choose_file():
    root = tk.Tk()
    root.withdraw()  # Hide the main window

    file_path = filedialog.askopenfilename()
    return file_path

def analyze_text_file(file_path):
    try:
        with open(file_path, 'r', encoding='utf-8') as file:
            text = file.read()
    except FileNotFoundError:
        return "File not found."

    # Remove punctuation and convert text to lowercase
    text = text.translate(str.maketrans('', '', string.punctuation)).lower()

    # Split text into words
    words = text.split()

    # Calculate word count
    word_count = len(words)

    # Calculate character count
    char_count = len(text)

    # Create a dictionary to store word frequency
    word_freq = {}
    for word in words:
        if word in word_freq:
            word_freq[word] += 1
        else:
            word_freq[word] = 1

    return {
        "Word Count": word_count,
        "Character Count": char_count,
        "Word Frequency": word_freq
    }

# Ask the user to choose a file
file_path = choose_file()
if file_path:
    # Analyze the chosen file
    analysis_result = analyze_text_file(file_path)

    # Display analysis results
    print("Analysis Results:")
    print(f"Word Count: {analysis_result['Word Count']}")
    print(f"Character Count: {analysis_result['Character Count']}\n")

    print("Word Frequency:")
    for word, frequency in analysis_result['Word Frequency'].items():
        print(f"{word}: {frequency}")
