#include <bits/stdc++.h>
#define EPS 1e-9
#define endl '\n'
#define MOD(_a, _n) (((a%n)+n)%n)
#define getSize(_s) (int)_s.size()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;


inline void fastInputOutput(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}



bool comb(pair<double, int> f, pair<double, int> s){
    if(f.first == s.first){
        return f.second < s.second;
    }
    return f.first > s.first;
}

int main(){

    fastInputOutput();
   

    int n,t1,t2;cin>>n>>t1>>t2;
    double k;cin>>k;
    k/=100.0;
    vector<pair<double, int>> growers;

    for(int i=0;i<n;i++){
        int vi, zi;cin>>vi>>zi;
        pair<double, int> currGrower;
        double f1 = t1*vi;
        f1 -= (k*f1);
        f1 += t2*zi;
        double s1 = t1*zi;
        s1 -= (k*s1);
        s1 += t2*vi;
        currGrower.first = max(f1, s1);
        currGrower.second = i+1;
        growers.push_back(currGrower);
    }

    sort(growers.begin(), growers.end(), comb);
    for(auto& grower:growers){
        cout<<grower.second<<' '<<fixed<<setprecision(2)<<grower.first<<endl;
    }

    return 0;
}
