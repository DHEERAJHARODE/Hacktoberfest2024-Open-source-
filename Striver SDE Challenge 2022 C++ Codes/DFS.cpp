void dfs(int node, vector<int>& ans, vector<bool>& vtd, vector<int> adj[]){
        ans.push_back(node);
        vtd[node]=true;
        for(auto i:adj[node]){
            if(!vtd[i]) dfs(i,ans,vtd,adj);
        }
    }
    
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        vector<bool> vtd(V+1,false);
        for(int i=0;i<V;i++){
            if(!vtd[i]) dfs(i,ans,vtd,adj);
        }
        return ans;
    }