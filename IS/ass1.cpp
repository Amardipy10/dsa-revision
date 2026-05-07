#include <iostream>
#include <string>

using namespace std;

int main() {
    string str = "Hello World";
    cout << "Original String: " << str << "\n\n";
    // 1. Bitwise AND operation
    cout << "Result of AND with 127: ";
    for (int i = 0; i < str.length(); i++) {
        // str[i] gets the character, & 127 applies the bitwise AND
        // (char) converts the numerical result back into a letter
        cout << (char)(str[i] & 127);
    }
    cout << "\n";

    // 2. Bitwise OR operation
    cout << "Result of OR with 127:  ";
    for (int i = 0; i < str.length(); i++) {
        // Applies the bitwise OR
        cout << (char)(str[i] | 127);
    }
    cout << "\n";
    
    // 3. Bitwise XOR operation
    cout << "Result of XOR with 127: ";
    for (int i = 0; i < str.length(); i++) {
        // Applies the bitwise XOR
        cout << (char)(str[i] ^ 127);
    }
    cout << "\n";
    return 0;
}