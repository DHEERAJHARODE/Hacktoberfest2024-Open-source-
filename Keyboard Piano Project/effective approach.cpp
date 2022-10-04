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
    int n;
    cin>>n;
    int a[100000];
    
    for(int i=0;i<n;i++){
    	int nu;
    	cin>>nu;
    	a[nu]=i+1;
	}
	int m;
	cin>>m;
	int v=0;
	int p=0;
	for(int i=0;i<m;i++){
		int q;
		cin>>q;
		v+=a[q];
		p+=n-a[p]+1;
	}
	cout<<v<<" "<<p;
	
    return 0;
}


