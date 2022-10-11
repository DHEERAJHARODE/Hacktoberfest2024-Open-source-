class Main
{
    // Function to find the length of the shortest common supersequence of
    // sequences `X[0…m-1]` and `Y[0…n-1]`
    public static int SCSLength(String X, String Y, int m, int n)
    {
        // if the end of either sequence is reached, return
        // the length of another sequence
        if (m == 0 || n == 0) {
            return n + m;
        }
 
        // if the last character of `X` and `Y` matches
        if (X.charAt(m - 1) == Y.charAt(n - 1)) {
            return SCSLength(X, Y, m - 1, n - 1) + 1;
        }
 
        // last character of `X` and `Y` don't match
        return Integer.min(SCSLength(X, Y, m, n - 1) + 1,
                        SCSLength(X, Y, m - 1, n) + 1);
    }
 
    public static void main(String[] args)
    {
        String X = "ABCBDAB", Y = "BDCABA";
        int m = X.length(), n = Y.length();
 
        System.out.print("The length of the shortest common supersequence is "
                        + SCSLength(X, Y, m, n));
    }
}
