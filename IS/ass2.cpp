#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Helper function to figure out the column reading order based on the key
vector<int> getColumnOrder(const string& key) {
    // Store characters and their original indices
    vector<pair<char, int>> charPos;
    for (int i = 0; i < key.length(); ++i) {
        charPos.push_back({key[i], i});
    }
    
    // Sort alphabetically. std::sort automatically sorts pairs by the first element.
    sort(charPos.begin(), charPos.end());
    
    // Extract just the original indices in their new sorted order
    vector<int> order(key.length());
    for (int i = 0; i < key.length(); ++i) {
        order[i] = charPos[i].second;
    }
    return order;
}

// Encryption Function
string encrypt(string text, string key) {
    int cols = key.length();
    int rows = (text.length() + cols - 1) / cols; // Math trick for ceiling division
    
    // Pad the text with 'X' so it perfectly fits the grid dimensions
    while (text.length() < rows * cols) {
        text += 'X';
    }

    vector<int> order = getColumnOrder(key);
    string cipherText = "";

    // Build the cipher text by reading down the columns in the calculated order
    for (int colIndex : order) {
        for (int r = 0; r < rows; ++r) {
            // Calculate the 1D index mapping to the 2D grid
            cipherText += text[r * cols + colIndex];
        }
    }
    return cipherText;
}

// Decryption Function
string decrypt(string cipher, string key) {
    int cols = key.length();
    int rows = cipher.length() / cols;
    
    vector<int> order = getColumnOrder(key);
    
    // Create an empty grid filled with spaces
    vector<string> grid(rows, string(cols, ' '));
    
    int currentIndex = 0;
    
    // Reconstruct the grid column by column using the sorted key order
    for (int colIndex : order) {
        for (int r = 0; r < rows; ++r) {
            grid[r][colIndex] = cipher[currentIndex++];
        }
    }

    // Read the grid row by row to get the plaintext back
    string plainText = "";
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            // Optional: You could add logic here to strip out the 'X' padding
            plainText += grid[r][c];
        }
    }
    return plainText;
}

int main() {
    string key = "HACK"; // Length 4
    // Message length is 15. It will require 4 rows (16 spots), so 1 'X' will be padded.
    string msg = "DEFENDTHECASTLE"; 
    
    cout << "--- Columnar Transposition Cipher ---\n\n";
    cout << "Original Message: " << msg << "\n";
    cout << "Encryption Key:   " << key << "\n\n";
    
    string cipher = encrypt(msg, key);
    cout << "Encrypted Result: " << cipher << "\n";
    
    string decrypted = decrypt(cipher, key);
    cout << "Decrypted Result: " << decrypted << "\n";
    
    return 0;
}