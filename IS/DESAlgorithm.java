import javax.crypto.Cipher;
import javax.crypto.KeyGenerator;
import javax.crypto.SecretKey;
import java.util.Base64;

public class DESAlgorithm {
    
    // Cipher objects for encryption and decryption
    private static Cipher encryptCipher;
    private static Cipher decryptCipher;

    public static void main(String[] args) {
        try {
            // 1. Generate a valid DES key
            KeyGenerator keyGen = KeyGenerator.getInstance("DES");
            SecretKey secretKey = keyGen.generateKey();

            // 2. Initialize the Ciphers
            // "DES/ECB/PKCS5Padding" is the standard algorithm/mode/padding scheme
            encryptCipher = Cipher.getInstance("DES/ECB/PKCS5Padding");
            encryptCipher.init(Cipher.ENCRYPT_MODE, secretKey);

            decryptCipher = Cipher.getInstance("DES/ECB/PKCS5Padding");
            decryptCipher.init(Cipher.DECRYPT_MODE, secretKey);

            // 3. The secret message
            String originalMessage = "Top Secret Mission: DEFEND THE CASTLE";
            System.out.println("--- Data Encryption Standard (DES) ---");
            System.out.println("Original Message:  " + originalMessage);

            // 4. Encrypt the message
            String encryptedMessage = encrypt(originalMessage);
            System.out.println("Encrypted (Base64): " + encryptedMessage);

            // 5. Decrypt the message
            String decryptedMessage = decrypt(encryptedMessage);
            System.out.println("Decrypted Message: " + decryptedMessage);

        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    /**
     * Encrypts a plain text string into a Base64 encoded cipher text.
     */
    private static String encrypt(String plainText) throws Exception {
        // Convert string to bytes
        byte[] utf8Bytes = plainText.getBytes("UTF8");
        
        // Perform encryption
        byte[] encryptedBytes = encryptCipher.doFinal(utf8Bytes);
        
        // Encode the raw bytes into a Base64 string so we can print it
        return Base64.getEncoder().encodeToString(encryptedBytes);
    }

    /**
     * Decrypts a Base64 encoded cipher text back into plain text.
     */
    private static String decrypt(String encryptedText) throws Exception {
        // Decode the Base64 string back into raw bytes
        byte[] decodedBytes = Base64.getDecoder().decode(encryptedText);
        
        // Perform decryption
        byte[] decryptedBytes = decryptCipher.doFinal(decodedBytes);
        
        // Convert bytes back to string
        return new String(decryptedBytes, "UTF8");
    }
}