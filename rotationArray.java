import java.util.Scanner;

public class rotationArray {
    public static void main(String[] args) {
        int[] arr = { 5, 6, 7, 8, 9, 10 };
        Scanner in = new Scanner(System.in);
        System.out.println("Enter the number of rotations: ");
        int d = in.nextInt();

        // ? APPROACH 1---------------USING TEMP ARRAY
        // usingTempArr(arr, d);

        // ? APPROACH 2---------------USING SHIFTING
        usingShifting(arr, d);
        in.close();
    }

    // APPROACH 1==========================
    static void usingTempArr(int[] arr, int d) {
        int[] temp = new int[arr.length];
        int j = 0;

        // before rotation-----------
        System.out.println("Before rotation");
        for (int i = 0; i < arr.length; i++)
            System.out.print(arr[i] + " ");

        // ROTATITING----------------------------
        for (int i = d; i < arr.length; i++) {
            temp[j++] = arr[i];
        }
        for (int i = 0; i < d; i++)
            temp[j++] = arr[i];
        arr = temp;

        // after rotation-----------
        System.out.println("\nAfter rotation");
        for (int i = 0; i < arr.length; i++)
            System.out.print(arr[i] + " ");
    }

    // APPROACH 2==========================

    static void usingShifting(int[] arr, int d) {
        int curr = 0;
        int temp;
        // BEFORE ROTATION----------
        System.out.println("Before rotation");
        for (int i = 0; i < arr.length; i++)
            System.out.print(arr[i] + " ");

        // ROTATING----------
        int i;
        while (curr < d) {
            temp = arr[0];
            for (i = 0; i < arr.length - 1; i++) {
                arr[i] = arr[i + 1];
            }
            arr[arr.length - 1] = temp;
            curr++;
        }

        // AFTER ROTATION----------
        System.out.println("\nafrer rotation");
        for (i = 0; i < arr.length; i++)
            System.out.print(arr[i] + " ");

    }
}