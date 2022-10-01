#include<bits/stdc++.h>
using namespace std;

// recursive solution
int MCM(int *arr, int i, int j){
	if(i >= j) return 0;
	
	int res = INT_MAX;
	for(int k=i; k<j; k++){
		int tempAns = MCM(arr, i, k) + MCM(arr, k+1, j) + arr[i-1]*arr[k]*arr[j];
		res = min(res, tempAns);
	}
	
	return res;
}

// memoization solution
int dp[100][100];
int MCM_M(int *arr, int i, int j){
	if(i >= j) return 0;
	
	if(dp[i][j] != -1) return dp[i][j];
	
	int res = INT_MAX;
	for(int k=i; k<j; k++){
		int tempAns = MCM_M(arr, i, k) + MCM_M(arr, k+1, j) + arr[i-1]*arr[k]*arr[j];
		res = min(res, tempAns);
	}
	
	return dp[i][j] = res;
}

int main(){
	int arr[] = {10, 20, 30, 40, 30};
	int n = sizeof(arr)/sizeof(int);
	memset(dp, -1, sizeof(dp));
	
	cout<<MCM_M(arr, 1, n-1);
	
	return 0;
}