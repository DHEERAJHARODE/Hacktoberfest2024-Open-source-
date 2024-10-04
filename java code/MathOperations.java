class MathOperations {
    // Method to calculate the square of an integer
    static int square(int number) {
        return number * number;
    }

    // Overloaded method to calculate the square of a double
    static double square(double number) {
        return number * number;
    }

    // Overloaded method to calculate the square of two integers
    static int square(int number1, int number2) {
        return number1 * number2;
    }
}

class R {
    public static void main(String[] args) {
        System.out.println(MathOperations.square(2));        // Calls square(int)
        System.out.println(MathOperations.square(3.5));      // Calls square(double)
        System.out.println(MathOperations.square(2, 3));     // Calls square(int, int)
    }
}
