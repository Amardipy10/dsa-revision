#include <iostream>
#include <cmath>

using namespace std;

// 1. Utility function to find the Greatest Common Divisor (GCD)
long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// 2. Binary Exponentiation under Modulo (Fast power algorithm)
// Calculates: (base ^ exp) % mod
long long modExp(long long base, long long exp, long long mod) {
    long long res = 1;
    base = base % mod;
    while (exp > 0) {
        // If exp is odd, multiply base with result
        if (exp % 2 == 1) {
            res = (res * base) % mod;
        }
        // exp must be even now
        exp = exp >> 1; // Divide exp by 2
        base = (base * base) % mod; // Square the base
    }
    return res;
}

// 3. Function to find the Private Key 'd'
// Calculates the modular inverse of e mod phi
long long modInverse(long long e, long long phi) {
    // A simple loop to find 'd' (For large numbers, the Extended Euclidean Algorithm is used)
    for (long long d = 2; d < phi; d++) {
        if ((e * d) % phi == 1) {
            return d;
        }
    }
    return 1;
}

int main() {
    cout << "--- RSA Algorithm Implementation ---\n\n";

    // Step 1: Choose two prime numbers
    long long p = 61;
    long long q = 53;
    cout << "Prime p = " << p << ", Prime q = " << q << "\n";

    // Step 2: Calculate n and phi
    long long n = p * q;
    long long phi = (p - 1) * (q - 1);
    cout << "Modulus (n) = " << n << "\n";
    cout << "Totient (phi) = " << phi << "\n";

    // Step 3: Choose 'e' such that 1 < e < phi and gcd(e, phi) == 1
    long long e = 2;
    while (e < phi) {
        if (gcd(e, phi) == 1) {
            break; // Found a valid public exponent
        }
        e++;
    }
    // We can also manually set 'e' if we want. Let's use 17 for this example.
    e = 17; 
    cout << "Public Exponent (e) = " << e << "\n";

    // Step 4: Calculate the Private Key 'd'
    long long d = modInverse(e, phi);
    cout << "Private Exponent (d) = " << d << "\n\n";

    cout << "PUBLIC KEY:  (" << e << ", " << n << ")\n";
    cout << "PRIVATE KEY: (" << d << ", " << n << ")\n\n";

    // --- The Message ---
    // Note: The message 'M' must be a number smaller than 'n'
    long long M = 65; 
    cout << "Original Message (M): " << M << "\n";

    // --- Encryption ---
    // C = (M ^ e) % n
    long long C = modExp(M, e, n);
    cout << "Encrypted Ciphertext (C): " << C << "\n";

    // --- Decryption ---
    // M = (C ^ d) % n
    long long decryptedM = modExp(C, d, n);
    cout << "Decrypted Message: " << decryptedM << "\n";

    return 0;
}