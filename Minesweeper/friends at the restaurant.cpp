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
		int a[n],b[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		for(int i=0;i<n;i++){
			cin>>b[i];
		}
		vi p;
		vi q;
		for(int i=0;i<n;i++){
			if(b[i]>=a[i]){
				p.pb(b[i]-a[i]);
			}
			else{
				q.pb(a[i]-b[i]);
			}
		}
		sort(p.begin(),p.end());
		sort(q.begin(),q.end());
//		for(int i=0;i<p.size();i++){
//			cout<<p[i]<<" ";
//		}
//		cout<<endl;
//		for(int i=0;i<q.size();i++){
//			cout<<q[i]<<" ";
//		}
//		cout<<endl;
		int ans=0;
		int x=p.size()-1;
		for(int i=q.size()-1;i>=0;i--){
			if(x<0){
				break;
			}
			if(p[x]>=q[i]){
				ans++;
				x--;
			}
			
		}
		cout<<ans+((x+1)/2)<<endl;
    }
    return 0;
}


