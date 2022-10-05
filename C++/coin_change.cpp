#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &coins, int idx, int sum, vector<vector<int>> &dp)
{
    if (sum == 0)
        return 0;
    if (sum < 0 || idx < 0)
        return 1e9;
    if (dp[idx][sum] != -1)
        return dp[idx][sum];

    int notPick = solve(coins, idx - 1, sum, dp);
    int pick = 1e9;

    if (coins[idx] <= sum)
    {
        pick = 1 + solve(coins, idx, sum - coins[idx], dp);
    }
    return dp[idx][sum] = min(pick, notPick);
}

int coinChange(vector<int> &coins, int amount)
{

    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
    int ans = solve(coins, coins.size() - 1, amount, dp);
    if (ans == 1e9)
        return -1;
    return ans;
}

int main()
{
    int n;
    cout<<"Enter number of coins"<<endl;
    cin>>n;

    vector<int> coins;
    for(int i=0;i<n;i++)
    {
        int ele;
        cin>>ele;
        coins.push_back(ele);
    }

    int amount;
    cout << "Enter Amount" << endl;
    cin>>amount;

    cout << coinChange(coins,amount)<<endl;
}



