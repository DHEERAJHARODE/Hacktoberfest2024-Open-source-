class Solution
{
public:
    int candy(vector<int> &ratings)
    {

        int n = ratings.size();

        vector<int> candies(n, 1);

        // left to right
        for (int i = 1; i < n; i++)
        {
            if (ratings[i] > ratings[i - 1] && candies[i] <= candies[i - 1])
                candies[i] = candies[i - 1] + 1;
        }

        // right to left
        for (int i = n - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1] && candies[i] <= candies[i + 1])
                candies[i] = candies[i + 1] + 1;
        }

        int count = 0;

        for (int i = 0; i < n; i++)
        {
            count += candies[i];
        }

        return count;
    }
};