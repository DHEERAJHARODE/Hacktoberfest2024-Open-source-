#include<bits/stdc++.h>
class three{
    public:
    int valu,idx,jdx;
};
struct cmp{
    bool operator()(three a, three b){
        return a.valu < b.valu;
    }
};
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
	sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    priority_queue<three, vector<three>,cmp> pq;
    vector<int> ans;
    set<pair<int, int>> s;
    pq.push({a[n-1]+b[n-1], n-1, n-1});
    s.insert({n-1,n-1});
    while(ans.size()!=k){
        three th=pq.top();
        pq.pop();
        int val=th.valu, i=th.idx, j=th.jdx;
        ans.push_back(val);
        if(i>0 and !s.count({i-1,j})){
            pq.push({a[i-1]+b[j],i-1,j});
            s.insert({i-1,j});
        }
        if(j>0 and !s.count({i,j-1})){
            pq.push({a[i]+b[j-1],i,j-1});
            s.insert({i,j-1});
        }
    }
    return ans;
}