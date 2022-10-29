#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll N=1e6+5,inf=1e18,mod=1e9+7;
#define test ll testcases;cin>>testcases; while(testcases--)
#define pb push_back
#define mp make_pair
#define pf push_front
#define ff first
#define ss second
#define vll vector<ll>
#define vld vector<ld>
#define pll pair<ll,ll> 
#define ppll pair<ll,pair<ll,ll>>
#define pld pair<ld,ld> 
#define vpll vector<pll>
#define vpld vector<pld>
#define all(X) X.begin(),X.end()
#define sz(x) ((ll)((x).size()))
const ld pi=3.141592653589793238;

ll constructST(vll &st, ll l, ll r, vll &arr, ll ind)
{
    if(l==r)
    {
        st[ind]=arr[l];
        return arr[l];
    }
    ll mid=(l+r)/2;
    st[ind]=constructST(st,l,mid,arr,2*ind+1) + constructST(st,mid+1,r,arr,2*ind+2);
    return st[ind];
}
    
ll getSum(vll &st, ll l, ll r, ll segS, ll segE, vll &arr, ll ind)
{
    if(l > segE || segS > r)
    {
        return 0;
    }
    else if(segS>= l && segE<=r)
    {
        return st[ind];
    }
    ll mid=(segS+segE)/2;
    return getSum(st,l,r,segS,mid,arr,2*ind+1) + getSum(st,l,r,mid+1,segE,arr,2*ind+2);
}

void updateST(vll &st, ll pos, ll diff, ll segS, ll segE, ll ind)
{
    st[ind]+=diff;
    if(segS!=segE)
    {
        ll mid=(segS+segE)/2;
        if(pos<=mid)
        {
            updateST(st,pos,diff,segS,mid,2*ind+1);
        }
        else
        {
            updateST(st,pos,diff,mid+1,segE,2*ind+2);
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m,i,q,p1,p2;
    cin>>n>>m;
    vll arr(n);
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    ll h = ceil(log2(n));
    vll st(pow(2,h+1)-1);
    constructST(st,0,n-1,arr,0);

    // for(i=0;i<st.size();i++)
    // {
    //     cout<<st[i]<<" ";
    // }
    // cout<<"\n";

    while(m--)
    {
        cin>>q>>p1>>p2;
        if(q==1)
        {
            updateST(st,p1,p2-arr[p1],0,n-1,0);
            arr[p1]=p2;
        }
        else
        {
            cout<<getSum(st,p1,p2-1,0,n-1,arr,0)<<"\n";
        }
    }
    return 0;
}
    
    
    
    
    
// WA
// 1. overflow
// 2. re-initialize global variables for every test case
// 3. edge cases like n=1 or some type of cases missing
    
// Run time error
// 1. division by zero
// 2. array bounds