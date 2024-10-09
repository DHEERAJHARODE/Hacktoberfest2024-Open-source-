#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices){
    int minProfit = INT_MAX;
    int maxProfit = 0;
    for (int i = 0; i < prices.size(); i++){
        minProfit = min(minProfit, prices[i]);
        maxProfit = max(maxProfit, prices[i] - minProfit);
    }
    return maxProfit;
}

int main(){
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(prices);
    return 0;
}