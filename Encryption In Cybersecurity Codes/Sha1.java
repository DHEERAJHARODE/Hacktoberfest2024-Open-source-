import java.math.BigInteger;
import java.nio.charset.StandardCharsets;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.Scanner;

class Sha1 {
    public static byte[] getSHA1(String input) throws NoSuchAlgorithmException {
        MessageDigest md = MessageDigest.getInstance("SHA-1");
        return md.digest(input.getBytes(StandardCharsets.UTF_8));
    }

    public static String toHexString(byte[] hash) {
        BigInteger number = new BigInteger(1, hash);
        StringBuilder hexString = new StringBuilder(number.toString(16));
        while (hexString.length() < 40) {  // SHA-1 hash is 160 bits or 40 hex digits
            hexString.insert(0, '0');
        }
        return hexString.toString();
    }

    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in)) {
            System.out.print("Enter a string to hash: ");
            String input = scanner.nextLine();
            System.out.println("HashCode Generated for the string is: " + toHexString(getSHA1(input)));
        } catch (NoSuchAlgorithmException e) {
            System.out.println("The Exception for wrong hashing algorithm: " + e);
        }
    }
}
