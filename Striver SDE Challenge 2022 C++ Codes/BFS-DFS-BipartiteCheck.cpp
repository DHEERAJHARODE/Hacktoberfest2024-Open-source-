//DFS
bool bip(int node, vector<int>& color, vector<vector<int>>& adj){
        for(int i:adj[node]){
            if(color[i]==-1){
                color[i]=1-color[node];
                if(!bip(i,color,adj)) return false;
            }
            else if(color[i]==color[node]) return false;   
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& adj) {
        // vector<vector<int>> adj(graph.size());
        // //make adj list
        // for(int i=0;i<graph.size();i++)
        //     adj[graph[i][0]].push_back(graph[i][1]);
        
        vector<int> color(adj.size(),-1);
        for(int i=0;i<adj.size();i++){
            if(color[i]==-1){
                color[i]=1;
                if(!bip(i,color,adj)) return false;
            }
        }
        return true;
    }

//BFS
    bool bip(int node, vector<vector<int>> adj, vector<int> color){
        color[node]=1;
        queue<int>q;
        q.push(node);
        while(!q.empty()){
            int x = q.front();
            q.pop();
            for(int it:adj[x]){
                if(color[it]==-1){
                    color[it]=1-color[x];
                    q.push(it);
                }
                else if(color[it]==color[x]) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1)
                if(!bip(i,adj,color)) return false;
        }
        return true;
    }