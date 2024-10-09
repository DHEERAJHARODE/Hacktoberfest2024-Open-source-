#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices){
    int n = prices.size(), profit = 0;
    for (int i = 1; i < n; i++){
        if (prices[i] > prices[i - 1]){
            profit += prices[i] - prices[i - 1];
        }
    }
    return profit;
}

int main(){
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(prices);
    return 0;
}