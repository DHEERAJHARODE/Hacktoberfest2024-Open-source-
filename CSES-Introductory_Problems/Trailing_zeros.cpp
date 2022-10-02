#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	long long int ans=0;
	int power=5;
	while(n/power>0)
	{
		ans+=n/power;
		power=power*5;
	}
	cout<<ans<<endl;
}