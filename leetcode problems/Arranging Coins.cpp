class Solution
{
public:
    int arrangeCoins(int n)
    {

        int l = 0, r = n;
        long mid = 0;

        while (l <= r)
        {
            mid = l + (r - l) / 2;
            long total = (mid * (mid + 1)) / 2;

            if (total == n)
                return mid;
            else if (total > n)
                r = mid - 1;
            else
            {
                l = mid + 1;
            }
        }
        return r;
    }
};