vector <int> bellman_ford(int V, vector<vector<int>> adj, int S) {
        vector<int> dis(V, 1e8);
        dis[S] = 0;
        for (int i = 1; i <= V - 1; i++) {
            for (int j = 0; j < adj.size(); j++) {
                if (dis[adj[j][0]] != 1e8 && dis[adj[j][0]] + adj[j][2] <
                                   dis[adj[j][1]])
                    dis[adj[j][1]] = 
                      dis[adj[j][0]] + adj[j][2];
            }
        }
        return dis;
    }