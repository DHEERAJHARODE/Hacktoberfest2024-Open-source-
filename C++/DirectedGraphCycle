// Graph algorithm

class cycleInDirectedGraph{
    bool checkCycle(int i, int currVis[], vector<int> &adj[]), int vis[]) {
        vis[i]=1;
        currVis[i]=1;
        for(auto &nbr: adj[i]){
            if(!vis[nbr]){
                if(checkCycle(nbr, currVis, adj, vis)
                    return true;
            if(currVis[i])
                retun true;
        }
        return false;
    }
public:
    bool isCyclic(int n, vector<int> &adj[]) {
        int vis[n];
        for(int i=0;i<n;i++){
            if(!vis[i]){
                int currVis[n];
                if(checkCycle(i, currVis, adj, vis))
                    return true;
            }
        }
        return false;
    }
};

/*
Time Complexity: O(n+v)
Space Complexity: O(n+v)
*/
