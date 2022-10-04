#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define INF 1e18
#define fo(a, c) for (int(a) = 0; (a) < (c); (a)++)
#define Fo(a, b, c) for (int(a) = (b); (a) <= (c); (a)++)
typedef pair<int, int> pi;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long int> vlli;
#define pb push_back
#define endl '\n'
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);

int main()
{
	IOS
    ll test=1;
    cin>>test;
    while (test--)
    {
        //your code goes here
		int n;
		cin>>n;
		string s;
		cin>>s;
		set<char> sett;
		for(int i=0;i<n;i++){
			sett.insert(s[i]);
		}
		int p = sett.size()*2;
		int q = s.length()-sett.size();
		cout<<p+q<<endl;
    }
    return 0;
}


