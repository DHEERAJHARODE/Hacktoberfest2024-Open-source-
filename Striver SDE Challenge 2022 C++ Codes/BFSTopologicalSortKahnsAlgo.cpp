vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int>indeg(V,0);
	    vector<int>ans;
	    
	    for(int i=0;i<V;i++){
	        for(auto it: adj[i]) {
	            indeg[it]++; 
	        }
	    }
	        
	    queue<int> q;
	    
	    for(int i=0;i<V;i++)
	        if(indeg[i]==0)
	            q.push(i);
	            
	    while(!q.empty()){
	        int x=q.front();
	        q.pop();
	        //queue contains elems which have indeg 0
	        ans.push_back(x);
            for(auto p:adj[x]){
                //visiting node so indeg -1
                indeg[p]--;
                if(indeg[p]==0)
                    q.push(p);
            }
	    }
	    return ans;
	}