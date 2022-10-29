#include <iostream>
using namespace std;

bool isPossible(int elements[], int sum, int n)
{
	int dp[sum + 1];

	// Initializing with 1 as sum 0 is
	// always possible
	dp[0] = 1;

	// Loop to go through every element of
	// the elements array
	for(int i = 0; i < n; i++)
	{

		// To change the values of all possible sum
		// values to 1
		for(int j = sum; j >= elements[i]; j--)
		{
			if (dp[j - elements[i]] == 1)
				dp[j] = 1;
		}
	}

	// If sum is possible then return 1
	if (dp[sum] == 1)
		return true;

	return false;
}

// Driver code
int main()
{
	int elements[] = { 6, 2, 5 };
	int n = sizeof(elements) / sizeof(elements[0]);
	int sum = 7;

	if (isPossible(elements, sum, n))
		cout << ("YES");
	else
		cout << ("NO");

	return 0;
}
