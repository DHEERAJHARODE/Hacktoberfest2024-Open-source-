#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;


void print(string input,string output,int c,int sum)
{
	if(c==sum)
	{
		cout<<output<<endl;
		return;
	}
	else if(input=="")
	{
		return;
	}
	else
	{
		print(input.substr(1),output+input[0],c+input[0]-'0',sum);
		print(input.substr(1),output,c,sum);
	}
}


int32_t main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	string input="127615";
	string output="";
	print(input,output,0,8);
}