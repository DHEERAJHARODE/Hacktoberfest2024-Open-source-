// C++ Program to find best buying and selling days
#include <bits/stdc++.h>
using namespace std;

// This function finds the buy sell
// schedule for maximum profit
void stockBuySell(int price[], int n)
{
	// Prices must be given for at least two days
	if (n == 1)
		return;

	// Traverse through given price array
	int i = 0;
	while (i < n - 1) {

		// Find Local Minima
		// Note that the limit is (n-2) as we are
		// comparing present element to the next element
		while ((i < n - 1) && (price[i + 1] <= price[i]))
			i++;

		// If we reached the end, break
		// as no further solution possible
		if (i == n - 1)
			break;

		// Store the index of minima
		int buy = i++;

		// Find Local Maxima
		// Note that the limit is (n-1) as we are
		// comparing to previous element
		while ((i < n) && (price[i] >= price[i - 1]))
			i++;

		// Store the index of maxima
		int sell = i - 1;

		cout << "Buy on day: " << buy
			<< "\t Sell on day: " << sell << endl;
	}
}

// Driver code
int main()
{
	// Stock prices on consecutive days
	int price[] = { 100, 180, 260, 310, 40, 535, 695 };
	int n = sizeof(price) / sizeof(price[0]);

	// Function call
	stockBuySell(price, n);

	return 0;
}

// This is code is contributed by rathbhupendra
