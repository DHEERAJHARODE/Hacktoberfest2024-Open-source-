class searchMatrix {
    public static boolean searchMatrix(int[][] matrix, int target) {
        int m = matrix.length;
        int n = matrix[0].length;
        int sr = 0;
        int er = m - 1;

        while (sr <= er) {
            int midr = (er + sr) / 2;
            if (matrix[midr][0] <= target && matrix[midr][n - 1] >= target) {
                int sc = 0;
                int ec = n - 1;
                while (sc <= ec) {
                    int midc = (sc + ec) / 2;
                    if (matrix[midr][midc] == target) {
                        return true;
                    } else if (matrix[midr][midc] > target) {
                        ec = midc - 1;
                    } else if (matrix[midr][midc] < target) {
                        sc = midc + 1;
                    }

                }
                return false;
            } else if (matrix[midr][0] < target && matrix[midr][n - 1] < target) {
                sr = midr + 1;
            } else if (matrix[midr][0] > target) {
                er = midr - 1;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        int[][] arr = { { 1, 3, 5, 7 }, { 10, 11, 16, 20 }, { 23, 30, 34, 60 } };
        System.out.println(searchMatrix(arr, 3));
    }
}
