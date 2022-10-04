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
		int n,q;
		cin>>n>>q;
		int a[n];
		int suma=0;
		for(int i=0;i<n;i++){
			cin>>a[i];
			suma+=a[i];
			
		}
		sort(a,a+n,greater<int>());
		for(int i=0;i<q;i++){
			int x;
			cin>>x;
			int p,q;
			int sum=0;
			if(x>suma){
				cout<<-1<<endl;
			}
			else if(x==sum){
				cout<<p<<endl;
			}
			else if(x>sum){
				for(int i=p;i<n;i++){
					sum+=a[i];
					if(sum>=x){
						q=i+1;
						cout<<i+1<<endl;
						break;
					}
				}
				p=q;
			}
			else{
				
				for(int i=0;i<n;i++){
					sum+=a[i];
					if(sum>=x){
						p=i+1;
						
						cout<<i+1<<endl;
						break;
						
					}
				}
				q=p;
			}
			
		}
		
    }
    return 0;
}


