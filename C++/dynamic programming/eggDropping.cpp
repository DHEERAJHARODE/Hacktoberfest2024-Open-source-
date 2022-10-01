#include<bits/stdc++.h>
using namespace std;

// recursive solution
int eggDrop(int e, int f){
	if(f==0 || f==1) return f;
	if(e == 1) return f;
	
	int res = INT_MAX;
	for(int k=1; k<=f; k++){
		int tempAns = 1 + max(eggDrop(e, f-k), eggDrop(e-1, k-1));
		res = min(res, tempAns);
	}
	
	return res;
}

// memoization solution
int dp[100][100];
int eggDrop_M(int e, int f){
	if(f==0 || f==1) return f;
	if(e == 1) return f;
	
	if(dp[e][f] != -1) return dp[e][f];
	
	int res = INT_MAX;
	for(int k=1; k<=f; k++){
		int tempAns = 1 + max(eggDrop(e, f-k), eggDrop(e-1, k-1));
		res = min(res, tempAns);
	}
	
	return dp[e][f] = res;
}

int main(){
	int egg = 2, floor = 10;
	memset(dp, -1, sizeof(dp));
	cout<<eggDrop_M(egg, floor);
	
	return 0;
}