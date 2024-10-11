#include <bits/stdc++.h>
using namespace std;

// Function to count the substrings
// having different first and last
// characters
int countSubstring(string s, int n)
{
	// Store the final count
	int ans = 0;

	// Loop to traverse the string
	for (int i = 0; i < n; i++) {

		// Counter for each iteration
		int cnt = 0;

		// Iterate over substrings
		for (int j = i + 1; j < n; j++) {

			// Compare the characters
			if (s[j] != s[i])

				// Increase count
				cnt++;
		}

		// Adding count of substrings
		// to the final count
		ans += cnt;
	}

	// Print the final count
	cout << ans;
}

// Driver Code
int main()
{
	// Given string
	string S = "abcab";

	// Length of the string
	int N = 5;

	// Function Call
	countSubstring(S, N);

	return 0;
}
