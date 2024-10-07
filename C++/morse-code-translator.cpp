#include <iostream>
#include <unordered_map>
#include <sstream>
#include <vector>

using namespace std;

// Define the Morse code mapping
unordered_map<char, string> morseCodeMap = {
    {'A', ".-"},    {'B', "-..."},  {'C', "-.-."},  {'D', "-.."},
    {'E', "."},     {'F', "..-."},  {'G', "--."},   {'H', "...."},
    {'I', ".."},    {'J', ".---"},  {'K', "-.-"},   {'L', ".-.."},
    {'M', "--"},    {'N', "-."},    {'O', "---"},   {'P', ".--."},
    {'Q', "--.-"},  {'R', ".-."},   {'S', "..."},   {'T', "-"},
    {'U', "..-"},   {'V', "...-"},  {'W', ".--"},   {'X', "-..-"},
    {'Y', "-.--"},  {'Z', "--.."},
    {'0', "-----"}, {'1', ".----"}, {'2', "..---"}, {'3', "...--"},
    {'4', "....-"}, {'5', "....."}, {'6', "-...."}, {'7', "--..."},
    {'8', "---.."}, {'9', "----."},
    {' ', "/"}
};

// Reverse mapping for Morse code to characters
unordered_map<string, char> reverseMorseCodeMap;

void initializeReverseMap() {
    for (const auto& pair : morseCodeMap) {
        reverseMorseCodeMap[pair.second] = pair.first;
    }
}

// Function to encrypt English text to Morse code
string encryptToMorse(const string& text) {
    string morseCode;
    for (char ch : text) {
        ch = toupper(ch);
        if (morseCodeMap.find(ch) != morseCodeMap.end()) {
            morseCode += morseCodeMap[ch] + " ";
        }
    }
    return morseCode;
}

// Function to decrypt Morse code to English text
string decryptFromMorse(const string& morse) {
    stringstream ss(morse);
    string morseChar;
    string englishText;

    while (ss >> morseChar) {
        if (reverseMorseCodeMap.find(morseChar) != reverseMorseCodeMap.end()) {
            englishText += reverseMorseCodeMap[morseChar];
        } else if (morseChar == "/") { // Space in Morse code
            englishText += " ";
        }
    }
    return englishText;
}

int main() {
    initializeReverseMap();
    
    string choice;
    while (true) {
        cout << "Choose an option:\n1. Encrypt English to Morse Code\n2. Decrypt Morse Code to English\n3. Exit\n";
        cin >> choice;
        cin.ignore(); // Ignore the newline after the choice

        if (choice == "1") {
            string text;
            cout << "Enter text to encrypt: ";
            getline(cin, text);
            string morseCode = encryptToMorse(text);
            cout << "Morse Code: " << morseCode << endl;
        } else if (choice == "2") {
            string morse;
            cout << "Enter Morse code to decrypt (use '/' for space): ";
            getline(cin, morse);
            string englishText = decryptFromMorse(morse);
            cout << "English Text: " << englishText << endl;
        } else if (choice == "3") {
            cout << "Exiting program." << endl;
            break; // Exit the loop and end the program
        } else {
            cout << "Invalid option! Please choose again." << endl;
        }
    }

    return 0;
}
