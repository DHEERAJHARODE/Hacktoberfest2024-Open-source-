#include<bits/stdc++.h>
using namespace std;

class Solution {

public:
    // Function to find minimum number of attempts needed in
    // order to find the critical floor.

    int min_moves(int eggs, int floors)
    {
        if (eggs == 1) {
            return floors;
        }
        if (floors == 0 || floors == 1) {
            return floors;
        }
        int ans = 1e9;
        for (int i = 1; i <= floors; i++) {

            // eggs break from this floor , so try below
            // floors
            int op1 = min_moves(eggs - 1, i - 1);

            // eggs break from this floor , so try remaining
            // above floors
            int op2 = min_moves(eggs, floors - i);

            // temp stores minimum moves to find thresold
            // floor in worst case
            int temp = 1 + max(op1, op2);

            // we have to minimize the maximum answer
            ans = min(ans, temp);
        }
        return ans;
    }

    int eggDrop(int n, int k) { return min_moves(n, k); }
};

int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}