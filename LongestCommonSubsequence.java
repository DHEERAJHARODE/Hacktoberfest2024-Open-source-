/* Longest Common Subsequence (LCS) problem
 * It finds the longest subsequence that is common to two given sequences.
 * In this implementation, the longestCommonSubsequence function takes two strings, text1 and text2, as input. 
 * It returns the length of the longest common subsequence between the two strings.
 */

public class LongestCommonSubsequence {
    public static int longestCommonSubsequence(String text1, String text2) {
        int m = text1.length();
        int n = text2.length();

        int[][] dp = new int[m + 1][n + 1];

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <=n; j++) {
                if (text1.charAt(i - 1) == text2.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1] + 1;
                } else {
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j] - 1]);
                  }
            }
        }
        return dp[m][n];
    }
    public  static void main(String[] args) {
        String text1 = "AGGTAB";
        String text2 = "GXTXAYB";
        int length = longestCommonSubsequence(text1, text2);
        System.out.println("Length of Longest Common Subsequence: " + length);
    }
}
