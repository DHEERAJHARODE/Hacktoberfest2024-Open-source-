class Solution {
public:
    int maxProfit(vector<int>& prices) {
            int profit = 0;
            int min_pr = INT_MAX;
            for(int i = 0 ;i<prices.size(); i++){
                    int cost = prices[i] - min_pr;
                    min_pr = min(min_pr,prices[i]);
                    profit = max(profit ,cost);
            }
            return profit;
        
    }
};
