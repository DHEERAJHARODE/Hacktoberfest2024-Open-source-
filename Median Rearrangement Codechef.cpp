#include <bits/stdc++.h>

using namespace std;


#define     mod             (int)1e9+7
#define     MOD             998244353
#define     ll              long long
#define     int              long long
#define     mp              make_pair
#define     deb(x)          cout<< x << endl
#define     inf        1e18
#define     F               first
#define     S               second
#define     pb              push_back
#define     pf              emplace_front
#define     all(p)          p.begin(), p.end()
#define     rep(i,a,b)      for( i=a;i<b;++i)
#define     repr(i,a,b)     for( i=a;i>=b;i--)
#define     up              upper_bound
#define     lb              lower_bound
#define     t()             int test;cin>>test;while(test--)
#define     setbits(x)      __builtin_popcountll(x)
#define     si              set<int>
#define     que_max         priority_queue <int>
#define     que_min         priority_queue <int, vi, greater<int> >
#define     IOS             ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define     endl            "\n"
#define isOn(S, j)                   (S & (1 << j))
#define setBit(S, j)                 (S |= (1 << j))
#define clearBit(S, j)               (S &= ~(1 << j))
#define toggleBit(S, j)              (S ^= (1 << j))
#define lowBit(S)                    (S & (-S))
#define setAll(S, n)                 (S = (1 << n) - 1)
#define modulo(S, N)                 ((S) & (N - 1))
#define isPowerOfTwo(S)              (!(S & (S - 1)))
#define nearestPowerOfTwo(S)         ((int)pow(2.0, (int)((log((double)S) / log(2.0)) + 0.5)))
#define turnOffLastBit(S)            ((S) & (S - 1))
#define turnOnLastZero(S)            ((S) | (S + 1))
#define turnOffLastConsecutiveBits(S) ((S) & (S + 1))
#define turnOnLastConsecutiveZeroes(S) ((S) | (S - 1))

typedef pair<int, int>  pii;
typedef pair<ll, ll>  pl;
typedef vector<int>   vi;
typedef vector<ll>    vl;
typedef vector<pii>   vpii;
typedef vector<pl>    vpl;
typedef vector<vi>    vvi;
typedef vector<vl>    vvl;


#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cout << name << " : " << arg1 << endl;
  //use cerr if u want to display at the bottom
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ','); cout.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}
#else
#define trace(...)
#endif
int mpow(int base, int exp);  
void ipgraph(int n, int m);
void dfs(int u, int par);

const int N = 100005, M = 100005;
//=======================

vl g[N];
int a[N];
ll check(vl& arr,ll md,ll mxcost)
{
  ll i,n=arr.size(),l=0,m=sqrt(n),cost=0,mn=1e18,c=0;
  rep(i,0,n)
  {
    if(l>=m/2&&arr[i]>=md)
    {
      while(i<n&&c<m)
      {
        cost+=arr[i];
        mn=min(mn,arr[i]);
        l-=m/2;
        c++;
        if(c==m)
          break;
        if(l>=m/2)
          i++;
        else
        {
          i+=(m/2-l)+1;
          l=m/2;
        }
      }
      // trace(md,i,mn);
      if(i>n||n-i-1<(m-m/2-1)*m)
        c=0;
      break;
    }
    else
      l++;
  }
  if(mxcost>=cost&&c==m)
    return mn;
  return -1;
}
void solve()
{
    ll i,j,n,m,k,v;
    cin>>n>>k;
    ll ans=INT_MIN;
    m=n;
    n*=n;
    vl arr(n);
    rep(i,0,n)
    cin>>arr[i];
    sort(all(arr));
    // rep(i,0,n)
    // trace(arr[i]);
    // ll mn=0;
    // i=m/2;
    // j=m;
    // while(j--)
    // {
    //   mn+=arr[i];
    //   i+=m-1;
    // }
    // if(k<mn)
    // {
    //   deb(-1);
    //   return;
    // }
    ll l=1,r=1e9+5,mid;
    while(l<=r)
    {
      mid=(l+r)/2;
      ll num=check(arr,mid,k);
      if(num==-1)
        r=mid-1;
      else
        ans=max(ans,num),l=mid+1;
    }
    if(ans==INT_MIN)
      deb(-1);
    else
    deb(ans);
}

int32_t main()
{
  IOS;

  t()
  {
       solve();
  }

}
int mpow(int base, int exp) {
  base %= (mod);
  int result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((ll)result * base) % (mod);
    base = ((ll)base * base) % (mod);
    exp >>= 1;
  }
  return result;
}

void ipgraph(int n, int m){
  int i, u, v;
  while(m--){
    cin>>u>>v;
    u--, v--;
    g[u].pb(v);
    g[v].pb(u);
  }
}

void dfs(int u, int par){
  for(int v:g[u]){
    if (v == par) continue;
    dfs(v, u);
  }
}
