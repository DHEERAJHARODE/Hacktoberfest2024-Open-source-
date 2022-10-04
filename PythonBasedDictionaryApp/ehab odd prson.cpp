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
    int a[n];
    for(int i=0;i<n;i++){
    	cin>>a[i];
	}
	int c1=0,c2=0;
	for(int i=0;i<n;i++){
		if(a[i]%2==0){
			c1++;
		}
		else{
			c2++;
		}
	}
	if(c1==n || c2==n){
		for(int i=0;i<n;i++){
			cout<<a[i]<<" ";
		}
	}
	else{
		sort(a,a+n);
		for(int i=0;i<n;i++){
			cout<<a[i]<<" ";
		}
	}
    return 0;
}


