import java.security.SecureRandom;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

public class RandomPasswordGenerator {
    public static void main(String[] args) {
        int length = 12; // Adjust the password length as needed
        String password = generateRandomPassword(length);
        System.out.println("Random Password: " + password);
    }

    public static String generateRandomPassword(int length) {
        String lowercase = "abcdefghijklmnopqrstuvwxyz";
        String uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        String digits = "0123456789";
        String specialChars = "!@#$%^&*()_+-=[]{}|;:,.<>?";

        String allChars = lowercase + uppercase + digits + specialChars;
        SecureRandom random = new SecureRandom();

        List<String> passwordChars = random.ints(length, 0, allChars.length())
                .mapToObj(allChars::charAt)
                .map(String::valueOf)
                .collect(Collectors.toList());

        // Ensure at least one character from each character set
        passwordChars.add(String.valueOf(lowercase.charAt(random.nextInt(lowercase.length())));
        passwordChars.add(String.valueOf(uppercase.charAt(random.nextInt(uppercase.length())));
        passwordChars.add(String.valueOf(digits.charAt(random.nextInt(digits.length())));
        passwordChars.add(String.valueOf(specialChars.charAt(random.nextInt(specialChars.length())));

        // Shuffle the characters to make the password random
        List<String> shuffledChars = Arrays.asList(new String[length]);
        for (String s : passwordChars) {
            int position;
            do {
                position = random.nextInt(length);
            } while (shuffledChars.get(position) != null);
            shuffledChars.set(position, s);
        }

        return String.join("", shuffledChars);
    }
}
