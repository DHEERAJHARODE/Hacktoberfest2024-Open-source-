#include<iostream>
#include<vector>
#include <queue>
#include <set>
using namespace std;
const int N = 1e5+7;
const int INF = 1e9+7;

vector<pair<int, int>> g[N];//for weighted graphs we have to insert the weight between 2 nodes 
// first element is node value and second element is the weight
void dijkstra(int source){
    vector<int> dis(N, INF);
    vector<bool> vis(N, 0);

    set<pair<int, int>> st; // first element would be weight and second element would be node value
    st.insert({0, source});
    dis[source] = 0;
    while(st.size()>0){
        auto node = *st.begin(); // this is how we take the minimum value from a set
        int v = node.second;
        int distance = node.first;
        st.erase(st.begin());
        if(vis[v]==1){
            continue;
        }
        vis[v] = 1;
        for(auto child: g[v]){
            int child_v = child.first;
            int child_wt = child.second;
            if(dis[v] + child_wt < dis[child_v]){
                st.insert({dis[v]+child_wt, child_v});
                dis[child_v] = dis[v] + child_wt;
            }
        }
    }

}
int main()
{   
    int n,m;
    for(int i=0; i<m; i++){
        int x, y, wt;
        cin>>x>>y>>wt;
        g[x].push_back({y,wt}); // for an undirected graph we have to push for g[y] also

    }
    return 0;
}