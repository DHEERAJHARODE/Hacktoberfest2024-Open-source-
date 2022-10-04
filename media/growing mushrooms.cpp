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
   	int n,k;
	double t1,t2;
    cin>>n>>t1>>t2>>k;
    t2 = (t2*(100-k))/100;
    double a[n],b[n];
    for(int i=0;i<n;i++){
    	cin>>a[i]>>b[i];
	}
	double c[n];
	for(int i=0;i<n;i++){
		if(t1>=t2){
			c[i]=t1*max(a[i],b[i])+t2*min(a[i],b[i]);
		}
		else if(t1<t2){
			c[i]=t2*max(a[i],b[i])+t1*min(a[i],b[i]);
		}
	}
	int d[n];
	for(int i=0;i<n;i++){
		d[i]=c[i];
	}
	sort(d,d+n,greater<int>());
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(d[i]==c[j]){
				cout<<j+1<<" "<<setprecision(2)<<d[i]<<endl;
				break;
			}
		}
	}
    return 0;
}


