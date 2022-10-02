#include<iostream>
using namespace std;

int main()
{
	string s;
	cin>>s;
	int ans=1;
	int curr=1;
	for(int i=1;i<s.size();i++)
		if(s[i]==s[i-1])
		{
			curr++;
			ans=max(ans,curr);
		}
		else
			curr=1;
	cout<<ans<<endl;
}