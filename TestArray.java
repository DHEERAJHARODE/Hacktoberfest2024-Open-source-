import java.util.Scanner;


class NegativeSizeException extends Exception {

	NegativeSizeException(String message) {
		super(message);
	}

}

class TestArray {
	public static void main(String args[]) throws NegativeSizeException {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter array size");
		int n = sc.nextInt();
		int arr[] = new int[n];
		System.out.println("Enter array elements ");
		for (int i = 0; i < n; i++) {
			int r = sc.nextInt();
			if (r < 0)
				throw new NegativeSizeException("Negative values not excepted");
			else
				arr[i] = r;
		}
		sc.close();
	}
}