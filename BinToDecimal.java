// This issue is for adding a new Java class BinTODecimal in the Maths package. The class contains a method to convert a binary number (provided as an integer) to its decimal equivalent. The goal is to provide functionality for binary-to-decimal conversion using basic mathematical operations.
public class BinToDecimal {
    public static int convertBinaryToDecimal(int binary) {
        int decimal = 0;
        int base = 1;

        while (binary > 0) {
            int lastDigit = binary % 10;
            decimal += lastDigit * base;
            binary = binary / 10;
            base = base * 2;
        }
        return decimal;
    }
}
