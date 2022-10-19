vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        vector<bool> vtd(V+1, false);

        //traversal for each component of graph whether connected to first node or not
        // for(int i=0;i<V;i++){
        //     if(!vtd[i]){
        //         queue<int> q;
        //         q.push(i);
        //         vtd[i]=true;
                
        //         while(!q.empty()){
        //             int val=q.front();
        //             q.pop();
        //             ans.push_back(val);
                    
        //             for(auto node:adj[val]){
        //                 if(!vtd[node]){
        //                     q.push(node);
        //                     vtd[node]=true;
        //                 }
        //             }
        //         }
        //     }
        // }

	  //traversal of part of graph connected to first node
        queue<int> q;
        q.push(0);
        vtd[0]=true;
        while(!q.empty()){
            int val=q.front();
            q.pop();
            ans.push_back(val);
            
            for(auto node:adj[val]){
                if(!vtd[node]){
                    q.push(node);
                    vtd[node]=true;
                }
            }
        }
        return ans;
    }