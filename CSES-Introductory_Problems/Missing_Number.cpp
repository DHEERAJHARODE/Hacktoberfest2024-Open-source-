#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int res=0;
	for(int i=1;i<n;i++)
	{	
		int a;
		cin>>a;
		res=res^i^a;
	}
	res=res^n;
	cout<<res<<endl;
	return 0;
}