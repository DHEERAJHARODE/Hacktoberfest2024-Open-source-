// C++ code for the above approach:

#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>& arr, int n,
		set<vector<int> >& ans,
		vector<int> v, int i)
{
	if (i >= n) {
		ans.insert(v);
		return;
	}

	// Not pick
	solve(arr, n, ans, v, i + 1);

	// Pick
	v.push_back(arr[i]);
	solve(arr, n, ans, v, i + 1);
}

vector<vector<int> > AllSubsets(
	vector<int> arr, int n)
{

	// Set of vectors to store
	// required unique subsets
	set<vector<int> > ans;

	sort(arr.begin(), arr.end());
	vector<int> v;
	solve(arr, n, ans, v, 0);

	// Vector of vectors to store final result
	vector<vector<int> > res;
	while (!ans.empty()) {
		res.push_back(*ans.begin());
		ans.erase(ans.begin());
	}
	return res;
}

// Print Function
void print(int N, vector<int>& A)
{
	vector<vector<int> > result = AllSubsets(A, N);

	// printing the output
	for (int i = 0; i < result.size(); i++) {
		cout << '(';
		for (int j = 0; j < result[i].size(); j++) {
			cout << result[i][j];
			if (j < result[i].size() - 1)
				cout << " ";
		}
		cout << "), ";
	}
	cout << "\n";
}

// Drivers code
int main()
{
	int N = 3;
	vector<int> A = { 2, 1, 2 };

	// Function Call
	print(N, A);
	return 0;
}
