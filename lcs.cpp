//approach 1 (DP1)

class Solution {
public:
    int lcs(string text1, string text2, int m, int n) {
        int dp[m + 1][n + 1];
        
        for(int i = 0; i <= m ; i++) {
            for(int j = 0; j <= n; j++) {
                if(i == 0 || j == 0) {
                    dp[i][j] = 0;
                }
            }
        }
        
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        return dp[m][n];
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        
        return lcs(text1, text2, m, n);
    }
};

//approach 2 (memoization 1)

class Solution {
public:
    int t[1001][1001];
    
    int lcs(string text1, string text2, int n, int m) {
        if(n == 0 || m == 0) {
            return 0;
        }
        
        if(t[n][m] != -1) {
            return t[n][m];
        }
        
        if(text1[n - 1] == text2[m - 1]) {
            return t[n][m] = 1 + lcs(text1, text2, n - 1, m - 1);
        }
        else {
            return t[n][m] = max(lcs(text1, text2, n, m - 1), lcs(text1, text2, n - 1, m));
        }
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        
        memset(t, -1, sizeof(t));
        return lcs(text1, text2, n, m);
    }
};

//approach 3 (recursion 1)

class Solution {
public:
    
    int lcs(string text1, string text2, int n, int m) {
        if(n == 0 || m == 0) {
            return 0;
        }
        
        if(text1[n - 1] == text2[m - 1]) {
            return 1 + lcs(text1, text2, n - 1, m - 1);
        }
        else {
            return max(lcs(text1, text2, n, m - 1), lcs(text1, text2, n - 1, m));
        }
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        
        return lcs(text1, text2, n, m);
    }
};


//approach 4 (DP2)

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        
        int **output = new int*[m + 1];
        
        for(int i = 0; i <= m; i++) {
            output[i] = new int[n + 1];
        }
        
        for(int j = 0; j <= n; j++) {
            output[0][j] = 0;
        }
        for(int i = 0; i <= m; i++) {
            output[i][0] = 0;
        }
        
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(text1[m - i] == text2[n - j]) {
                    output[i][j] = 1 + output[i - 1][j - 1];
                }
                else {
                    int a = output[i - 1][j];
                    int b = output[i][j - 1];
                    int c = output[i - 1][j - 1];
                    
                    int ans = max(a, max(b, c));
                    output[i][j] = ans;
                }
            }
        }
        return output[m][n];
    }
};

//approach5 (memoization 2)


class Solution {
public:
    
    int lcs_mem(string text1, string text2, int **output) {
        int m = text1.size();
        int n = text2.size();
        
        if(text1.size() == 0 || text2.size() == 0) {
            return 0;
        }
        
        if(output[m][n] != -1) {
            return output[m][n];
        }
        
        int ans;
        if(text1[0] == text2[0]) {
            return 1 + lcs_mem(text1.substr(1), text2.substr(1), output);
        }
        else {
            int x = lcs_mem(text1.substr(1), text2, output);
            int y = lcs_mem(text1, text2.substr(1), output);
            int z = lcs_mem(text1.substr(1), text2.substr(1), output);
            
            ans = max(x, max(y, z));
        }
        
        output[m][n] = ans;
        
        return ans;
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        
        int **output = new int*[m + 1];
        for(int i = 0; i < m + 1; i++) {
            output[i] = new int[n + 1];
            for(int j = 0; j < n + 1; j++) {
                output[i][j] = -1;
            }
        }
        return lcs_mem(text1, text2, output);
    }
};


//approach 6 (recursion 2)

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if(text1.size() == 0 || text2.size() == 0) {
            return 0;
        }
        
        if(text1[0] == text2[0]) {
            return 1 + longestCommonSubsequence(text1.substr(1), text2.substr(1));
        }
        else {
            int x = longestCommonSubsequence(text1.substr(1), text2);
            int y = longestCommonSubsequence(text1, text2.substr(1));
            int z = longestCommonSubsequence(text1.substr(1), text2.substr(1));
            
            return max(x, max(y, z));
        }
    }
};
