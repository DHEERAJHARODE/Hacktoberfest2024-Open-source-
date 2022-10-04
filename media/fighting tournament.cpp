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
		int n,l;
		cin>>n>>l;
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		int b[n];
		for(int i=0;i<n;i++){
			b[i]=0;
		}
		int p=0;
		int max=0;
		for(int i=0;i<n;i++){
			if(a[i]>max){
				max=a[i];
				p=i;
			}
		}
		int q=0;
		int r=1;
		while(q!=p){
			
			if(a[q]>a[q+r]){
				b[q]++;
				r++;
			}
			else if(a[q]<a[q+r]){
				b[q+r]++; 
				q=q+r;
				r=1;
			}
		}
		int sum[n+1];
		sum[0]=0;
		for(int i=1;i<=n;i++){
			sum[i]=sum[i-1]+b[i-1];
		}
		for(int f=0;f<l;f++){
			int i,k;
			cin>>i>>k;
			if(i==p+1 && p==0){
				cout<<k<<endl;
			}
			else if(i>p+1){
				cout<<0<<endl;
			}
			else if(i==p+1 && k>p-1){
				cout<<k-p+1<<endl;
			}
			else if(i==p+1 && k<=p-1){
				cout<<0<<endl;
			}
			else if(i<p+1 && k>p-1){
				cout<<b[i-1]<<endl;
			}
			else if(i<p+1 && k<=p-1){
				if(b[i-1]==0){
					cout<<0<<endl;
				}
				else{
					if(k<=sum[i-1]){
						cout<<0<<endl;
					}
					else if(k>sum[i-1] && k<=sum[i]){
						cout<<k-sum[i-1]<<endl;
					}
					else if(k>sum[i]){
						cout<<b[i-1]<<endl;
					}
				}
			}
		}		
    }
    return 0;
}


