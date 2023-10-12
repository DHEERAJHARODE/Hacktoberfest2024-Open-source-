import java.util.Arrays;

class CoinChange {
	static long count(int coins[], int n, int sum)
{
	// dp[i] will be storing the number of solutions for
	// value i. We need sum+1 rows as the dp is
	// constructed in bottom up manner using the base case
	// (sum = 0)
	int dp[] = new int[sum + 1];

	// Base case (If given value is 0)
	dp[0] = 1;

	// Pick all coins one by one and update the dp[]
	// values after the index greater than or equal to the
	// value of the picked coin
	for (int i = 0; i < n; i++)
		for (int j = coins[i]; j <= sum; j++)
			dp[j] += dp[j - coins[i]];

	return dp[sum];
}

	// Driver Function to test above function
	public static void main(String args[])
	{
		int coins[] = { 1, 2, 3 };
		int n = coins.length;
		int sum = 5;
		System.out.println(count(coins, n, sum));
	}
}
// This code is contributed by Pankaj Kumar
