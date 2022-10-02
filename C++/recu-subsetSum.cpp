#include<bits/stdc++.h>
using namespace std;
void subs(vector<int>& input,vector<int>& output,int index,int sum)
{
	if(index==input.size())
	{
		output.push_back(sum);
		return;
	}
	subs(input,output,index+1,sum+input[index]);
	subs(input,output,index+1,sum);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	vector<int>input={2,5,4};
	vector<int>output;
	subs(input,output,0,0);
	sort(output.begin(),output.end());
	for(int i=0;i<output.size();++i)
	{
		cout<<output[i]<<" ";
	}


}