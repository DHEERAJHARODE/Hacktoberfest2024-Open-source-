bool cyclic(int node, vector<vector<int>>& adj, vector<int>& vtd){
        //if you try to process a node that is a;ready processing => cycle!
        if(vtd[node]==2) return true;
        
        vtd[node]=2;
        for(int i=0;i<adj[node].size();i++){
            //skip processed adj nodes
            if(vtd[adj[node][i]]!=1)
                //return true if cycle found
                if(cyclic(adj[node][i],adj,vtd)) return true;
        }
        //mark processed
        vtd[node]=1;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& preq)                     {
        //0-not visited
        //1-processed
        //2-processing
        vector<vector<int>> adj(numCourses);
        //make adj list
        for(int i=0;i<preq.size();i++)
            adj[preq[i][0]].push_back(preq[i][1]);
        
        vector<int> vtd(numCourses,0);
        for(int i=0;i<numCourses;i++)
            if(vtd[i]==0)
                if(cyclic(i,adj,vtd))
                    return false;
        return true;
    }