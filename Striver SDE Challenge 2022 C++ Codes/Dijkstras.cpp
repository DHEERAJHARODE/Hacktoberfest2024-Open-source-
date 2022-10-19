vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> dist(V, 1e8);
        dist[S]=0;
        priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > pq;
        pq.push({0,S});
        while(!pq.empty()){
            auto u=pq.top();
            pq.pop();
            for(auto it: adj[u.second]){
                if(dist[it[0]] != 1e8 && dist[it[0]] + it[2] < dist[it[1]]){
                    dist[it[1]] = dist[it[0]] + it[2];
                    pq.push({dist[it[1]], it[1]});
                }
            }
        }
        return dist;
    }