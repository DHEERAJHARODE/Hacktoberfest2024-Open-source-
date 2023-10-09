class Solution

{
public:
    // Function to detect cycle in a directed graph.
    bool checkCycle(int s,vector<int> adj[],vector<bool>&vis,vector<bool>&dfsVis){
        vis[s]=true;
        dfsVis[s]=true;
        for(int u:adj[s]){
            if(!vis[u]){
                if(checkCycle(u,adj,vis,dfsVis))return true;
            }
            else if(dfsVis[u])return true;
        }
        dfsVis[s]=false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool>vis(V,false),dfsVis(V,false);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(checkCycle(i,adj,vis,dfsVis))return true;
            }
        }
        return false;
    }
};
