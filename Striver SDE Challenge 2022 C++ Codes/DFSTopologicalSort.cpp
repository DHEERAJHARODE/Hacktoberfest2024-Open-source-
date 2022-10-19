//DFS
	void dfs(int node, vector<bool>& vtd, vector<int> adj[], stack<int>& topo){
	    vtd[node]=true;
	    for(auto it:adj[node])
	        if(!vtd[it]) dfs(it,vtd,adj,topo);
	    topo.push(node);
	}
	vector<int> topoSort(int V, vector<int> adj[]){
	    vector<int>ans;
	    stack<int>topo;
	    vector<bool>vtd(V+1,false);
	    for(int i=0;i<V;i++)
	        if(!vtd[i])
	            dfs(i,vtd,adj,topo);
	    while(!topo.empty()){
	        ans.push_back(topo.top());
	        topo.pop();
	    }
	    return ans;
	}