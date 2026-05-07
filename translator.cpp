#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include <sstream>

using namespace std;

// Two maps for O(1) two-way translation
unordered_map<string, string> charToMorse;
unordered_map<string, string> morseToChar;

// Helper to load the dictionary you generated
bool loadDictionary() {
    ifstream file("shiva_shakti_codes.txt");
    if (!file.is_open()) {
        cout << "Error: Run 'shiva_tree.exe' first to generate the codes!\n";
        return false;
    }

    string line;
    // Skip the header line
    getline(file, line); 

    while (getline(file, line)) {
        if (line.empty()) continue;

        // Parse lines formatted like: क : .....-
        size_t colonPos = line.find(" : ");
        if (colonPos != string::npos) {
            string character = line.substr(0, colonPos);
            string code = line.substr(colonPos + 3);
            
            charToMorse[character] = code;
            morseToChar[code] = character;
        }
    }
    file.close();
    return true;
}

// Function to encode Devangari to Morse
void encode(const string& text) {
    cout << "\nEncoding: " << text << "\nResult: ";
    
    // Simple UTF-8 parser for the input string
    for (size_t i = 0; i < text.length(); ) {
        int cplen = 1;
        unsigned char c = text[i];
        if ((c & 0xF8) == 0xF0) cplen = 4;
        else if ((c & 0xF0) == 0xE0) cplen = 3;
        else if ((c & 0xE0) == 0xC0) cplen = 2;

        string uchar = text.substr(i, cplen);
        
        // Ignore spaces
        if (uchar != " ") {
            if (charToMorse.find(uchar) != charToMorse.end()) {
                cout << charToMorse[uchar] << " ";
            } else {
                cout << "[?] "; // Character not found in corpus
            }
        } else {
            cout << " / "; // Word separator
        }
        i += cplen;
    }
    cout << "\n";
}

// Function to decode Morse back to Devangari
void decode(const string& morseText) {
    cout << "\nDecoding: " << morseText << "\nResult: ";
    
    stringstream ss(morseText);
    string code;
    
    while (ss >> code) {
        if (code == "/") {
            cout << " ";
        } else if (morseToChar.find(code) != morseToChar.end()) {
            cout << morseToChar[code];
        } else {
            cout << "[?]"; // Invalid code
        }
    }
    cout << "\n";
}

int main() {
    // Enable UTF-8 output for Windows console
    system("chcp 65001 > nul");
    
    if (!loadDictionary()) return 1;

    cout << "--- SHIVA-SHAKTI MORSE TRANSLATOR ---\n";
    cout << "Loaded " << charToMorse.size() << " optimized characters.\n\n";

    int choice;
    string input;

    while (true) {
        cout << "\n1. Encode (Devanagari to Morse)\n";
        cout << "2. Decode (Morse to Devanagari)\n";
        cout << "3. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;
        cin.ignore(); // Clear the newline

        if (choice == 1) {
            cout << "Enter Devanagari text (e.g. यश): ";
            getline(cin, input);
            encode(input);
        } else if (choice == 2) {
            cout << "Enter Morse code (space separated, use / for word breaks): ";
            getline(cin, input);
            decode(input);
        } else if (choice == 3) {
            break;
        } else {
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}