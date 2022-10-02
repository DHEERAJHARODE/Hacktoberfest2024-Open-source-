#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	long long int ans=0;
	long long int prev;
	cin>>prev;
	for(int i=1;i<n;i++)
	{
		long long int curr;
		cin>>curr;
		if(curr<prev)
			ans+=prev-curr;
		else
			prev=curr;
	}
	cout<<ans<<endl;
}