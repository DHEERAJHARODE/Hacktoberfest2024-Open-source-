#include<stdio.h>
#include<iostream>
using namespace std;
void funb(int n);
void funa(int n){
	if(n>0){
		cout<<n<<endl;
		funb(n-1);
	}
}
void funb(int n){
	if(n>1){
		cout<<n<<endl;
		funa(n/2);
	}
}
int main(){
	int a=20;
	funa(20);
}
