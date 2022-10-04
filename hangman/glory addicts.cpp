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
		int a[n];
		int b[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		for(int i=0;i<n;i++){
			cin>>b[i];
		}
		vi v1;
		vi v2;
		for(int i=0;i<n;i++){
			if(a[i]==1){
				v1.pb(b[i]);
			}
			else{
				v2.pb(b[i]);
			}
		}
		sort(v1.begin(),v1.end(),greater<int>());
		sort(v2.begin(),v2.end(),greater<int>());
		ll sum=0;
		if(v1.size()>v2.size()){
			sum+=v1[v1.size()-1];
			for(int i=0;i<v2.size();i++){
				sum+=2*v1[i]+2*v2[i];
			}
			for(int i=v2.size();i<v1.size()-1;i++){
				sum+=v1[i];
			}
		}
		else if(v1.size()<v2.size()){
			sum+=v2[v2.size()-1];
			for(int i=0;i<v1.size();i++){
				sum+=2*v2[i]+2*v1[i];
			}
			for(int i=v1.size();i<v2.size()-1;i++){
				sum+=v2[i];
			}
		}
		else if(v1.size()==v2.size()){
			if(v1[v1.size()-1]>=v2[v2.size()-1]){
				sum+=v2[v2.size()-1]+2*v1[v1.size()-1];
			}
			else{
				sum+=v1[v1.size()-1]+2*v2[v2.size()-1];
			}
			for(int i=0;i<v1.size()-1;i++){
				sum+=2*v1[i]+2*v2[i];
			}
		}
		cout<<sum<<endl;
    }
    return 0;
}


