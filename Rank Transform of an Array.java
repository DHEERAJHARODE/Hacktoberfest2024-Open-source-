class Solution {
    public int[] arrayRankTransform(int[] arr) {
        int len = arr.length;
        int max = Integer.MIN_VALUE;
        int min = Integer.MAX_VALUE;
        for (int val: arr) {
            max = Math.max(val, max);
            min = Math.min(val, min);
        } 
        int[] res = new int[len];
        if (max - min > 200 && arr.length < 10) {
            int [] tmp = arr.clone();
            Arrays.sort(arr);
            int index = 1;
            boolean isRepeat = false;
            for (int i = 0; i < arr.length; i++) {
                int val = arr[i];
                isRepeat = false;
                for (int j = 0; j < tmp.length; j++) {
                    if (tmp[j] == val) {
                        if (isRepeat) {
                            i++;
                        }
                        res[j] = index;
                        isRepeat = true;
                    }
                }
                index++;
            }
            return res;

        } 
        else {
        int[] nums = new int [max - min + 1];
            for (int i = 0; i < arr.length; i++) {
                nums[arr[i] - min] = 1;
            }

            int rank = 1;
            for (int i = 0; i < max - min + 1; i++) {
                if (nums[i] == 1) {
                    nums[i] = rank;
                    rank++;
                }
            }
             for (int i = 0; i < arr.length; i++) {
                res[i] = nums[arr[i]-min];
            }

            return res;
        }
    }
}
