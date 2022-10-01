/*


Problem Statement : Given t number of testcases, for each testcase, you are given a string s, now tell whether
this string contains all unique characters or some characters are repeated in it. If string contains unique characters 
print "True, String contains distinct characters only", else print "False, String do not contain distinct characters".

For Example -> 
Input:- 
4
abcde
abbd
yaaaa
cab$@

Output:- 
True, String contains distinct characters only
False, String do not contain distinct characters
False, String do not contain distinct characters
True, String contains distinct characters only


*/

#include<bits/stdc++.h>
using namespace std;


#define ll      long long int
#define endl    "\n"
#define all(v)  v.begin(), v.end()
#define vi      vector<int> 

bool areDistinctusing_Set(string str){
	set<char> st ;
	int len = str.size() ; 
	for (int i = 0; i < len; ++i)
	{
		st.insert(str[i]);
	}

	if (str.size() == st.size())
	{
		return true; 
	}
	return false; 

}

void solve()
{

	//Input  : 
	//first line : no of testcases (n)
	//next n lines contains strings to be checked for distinct characters

	vector<string> vec = {"False, String do not contain distinct characters" , "True, String contains distinct characters only"} ; 
	string s ; cin >> s ;
	cout << vec[areDistinctusing_Set(s)] << endl  ; 


	
}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	ll t = 1 ; 
	cin >> t ; 
	while(t--) solve(); 
    
    return 0 ; 
}