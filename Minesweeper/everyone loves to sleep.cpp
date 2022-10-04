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
    ll test;
    cin>>test;
    while (test--)
    {
        //your code goes here
        int n,h,m;
        cin>>n>>h>>m;
        int a[n],b[n];
        for(int i=0;i<n;i++){
        	cin>>a[i]>>b[i];
		}
		int min = 24*60;
		for(int i=0;i<n;i++){
			int x = a[i]-h;
			int y = b[i]-m;
			int p = x;
			int q = y;
			int z;
			if(x>0 && y>0){
				z = x*60+y;
			}
			else if(x>0 && y==0){
				z = x*60 +y;
			}
			else if(x>0 && y<0){
				z = (x-1)*60 + y+60;
			}
			else if(x==0 && y>0){
				z = x*60 + y;
			}
			else if(x==0 && y==0){
				z = x*60 +y;
			}
			else if(x==0 && y<0){
				z = (x+23)*60 + y+60;
			}
			else if(x<0 && y>0){
				z = (x+24)*60 + y;
			}
			else if(x<0 && y==0){
				z = (x+24)*60 + y;
			}
			else if(x<0 && y <0){
				z = (x+23)*60 + y+60;
			}
			 
			if(z<min){
				min = z;
			}
		}
		cout<<min/60<<" "<<min%60<<endl;
			
    }
    return 0;
}


