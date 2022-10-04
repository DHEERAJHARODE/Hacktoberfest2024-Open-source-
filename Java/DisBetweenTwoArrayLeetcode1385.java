public class DisBetweenTwoArrayLeetcode1385 {
    public static void main(String[] args) {
        int[] a1 = {1,4,2,3}, a2 = {-4,-3,6,10,20,30};
        int d = 3;
        System.out.println(findTheDistanceValue(a1,a2,d));
    }
    static int findTheDistanceValue(int[] arr1, int[] arr2, int d) {
        int c=0;
        for (int value : arr1) {
            int k=0;
            for (int i : arr2) {
                if (Math.abs(value - i) <= d) {
                    k = 1;
                    break;
                }
            }
            if (k == 0)
                c++;
        }
        return c;
    }
}
