int findMinimumCoins(int amount) 
{
    int ans=0;
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int j=8;//no of coins
    while(amount && j>=0){
        if(amount-coins[j]>=0){
            amount -= coins[j];
            ans++;
        }
        else j--;
    }
    return ans;
}
