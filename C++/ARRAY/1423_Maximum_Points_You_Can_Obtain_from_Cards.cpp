#include<bits/stdc++.h>
using namespace std;


int maxScore(vector<int>& cardPoints, int k) {
    int sum=0,n=cardPoints.size();
    for(int i=0;i<k;i++) sum+=cardPoints[i];

    int ans=sum;
    int i=k-1;
    int j=n-1;
    while(j>=0 && i>=0){
        sum = sum - cardPoints[i] + cardPoints[j];
        ans = max(ans,sum);
        i--;
         j--;
    }
    return ans;
}

int main(){
    vector<int> cardPoints = {1,2,3,4,5,6,1};
    int k = 3;
    cout << maxScore(cardPoints, k) << endl;
    return 0;
}