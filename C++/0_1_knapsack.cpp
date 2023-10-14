#include <iostream>
#include <vector>

using namespace std;

// Structure to represent an item
struct Item {
    int weight;
    int value;
};

int knapsack(int W, vector<Item>& items) {
    int n = items.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (items[i - 1].weight <= w) {
                dp[i][w] = max(dp[i - 1][w], items[i - 1].value + dp[i - 1][w - items[i - 1].weight]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {
    int W = 10; // Maximum weight the knapsack can hold

    vector<Item> items = {
        {2, 6},
        {2, 10},
        {3, 12},
        {4, 13},
        {5, 16}
    };

    int maxVal = knapsack(W, items);

    cout << "Maximum value that can be obtained: " << maxVal << endl;

    return 0;
}
