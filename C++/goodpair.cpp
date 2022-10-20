#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[100001],sum;
void solve(){
	cin>>n;
   
   map<int,int> m;

   for (int i = 1; i <= n; i++)
   {
      cin>>a[i];
      m[a[i]]++;
   }

   sum=0;
   for(auto i:m){
         sum+=i.second*(i.second-1)/2;
   }
   cout<<sum<<endl;
}

signed main(){
	int t; cin>>t;
	while(t--)solve();
	return 0;
}