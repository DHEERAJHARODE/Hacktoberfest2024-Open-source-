#include<bits/stdc++.h>
using namespace std;

int fibo(int n){
	//nth term of fibonacci
	if(n==0)
		return 0;
	if(n==1)
		return 1;
	return fibo(n-1)+fibo(n-2);
}

int main(){
	int n;
	cin>>n;
	int a = fibo(n);
	cout<<a;
	return 0;
}