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
    int s,n;
    cin>>s>>n;
    int a[n];
    int b[n];
    for(int i=0;i<n;i++){
    	cin>>a[i]>>b[i];
	}
    vector<pair<int,int> > v;
    for(int i=0;i<n;i++){
    	v.pb(make_pair(a[i],b[i]));
	}
	sort(v.begin(),v.end());
	int flag=1;
	for(int i=0;i<n;i++){
		if(s>v[i].first){
			s+=v[i].second;
		}
		else{
			flag=0;
			break;
		}
	}
	if(flag==0){
		cout<<"NO";
	}
	else{
		cout<<"YES";
	}
    return 0;
}


