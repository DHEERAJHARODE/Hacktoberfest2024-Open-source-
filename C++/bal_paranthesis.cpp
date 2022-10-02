#include <bits/stdc++.h>
#include<stack>
using namespace std;

int main() 
{
    string s="{()}][";
    
    stack<char> st;
    int flag=0;
    
    for(int i=0;i<s.length();i++)
    {
    	if(s[i]=='{' or s[i]=='[' or s[i]=='(')
    	{
    		st.push(s[i]);
		}
		
		else
		{
			if((s[i]=='}' and st.top()=='{') or (s[i]==']' and st.top()=='[') or (s[i]==')' and st.top()=='('))
			{
				st.pop();
			}
			else
			{
				flag=1;
				break;
			}
		}
	}
	
	if(flag==1)
	{
		cout<<"NO"<<endl;
	}
	
	else
	{
		cout<<"YES"<<endl;
	}
	
	return 0;
}

