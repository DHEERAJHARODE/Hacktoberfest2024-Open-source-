class Solution
{
public:
    int numberOfBits(int n)
    {
        return log2(n) + 1;
    }

    int concatenatedBinary(int n)
    {
        long ans = 0, MOD = 1e9 + 7;

        for (int i = 1; i <= n; ++i)
        {
            int len = numberOfBits(i);
            ans = ((ans << len) % MOD + i) % MOD;
        }
        return ans;
    }
};