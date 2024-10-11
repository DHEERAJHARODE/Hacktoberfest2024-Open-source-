// CPP program to find largest sub
// string with same characters
#include <bits/stdc++.h>
using namespace std;

// Function to find largest sub
// string with same characters
int Substring(string s)
{

	int ans = 1, temp = 1;

	// Traverse the string
	for (int i = 1; i < s.size(); i++) {
		// If character is same as
		// previous increment temp value
		if (s[i] == s[i - 1]) {
			++temp;
		}
		else {
			ans = max(ans, temp);
			temp = 1;
		}
	}
	ans = max(ans, temp);

	// Return the required answer
	return ans;
}

// Driver code
int main()
{
	string s = "abcdddddeff";

	// Function call
	cout << Substring(s);

	return 0;
}
