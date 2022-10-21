#include <bits/stdc++.h>
using namespace std;

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> adj[n];

    int a, b, wt;
    for(int i = 0; i < n; i++) {
        cin >> a >> b >> wt;
        adj[a].push_back(make_pair(b, wt));
        adj[b].push_back(make_pair(a, wt));
    }

    int key[n];
    bool mst[n];
    int parent[n];

    for(int i = 0; i < n; i++) {
        key[i] = INT_MAX, mst[i] = false, parent[i] = -1;
    }

    key[0] = 0;
    parent[0] = -1;

    for(int count = 0; count < n-1; count++) {
        int mini = INT_MAX, u;

        for(int v = 0; v < n; v++) {
            if(mst[v] == false && key[v] < mini){
                mini = key[v], u = v;
            }
        }

        mst[u]= true;

        for(auto it: adj[u]) {
            int v = it.first;
            int weight = it.second;
            if(mst[v] == false && weight < key[v]) {
                key[v] = weight, parent[v] = u;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        cout << parent[i] << "-" << i << "\n";
    }

    return 0;
}
