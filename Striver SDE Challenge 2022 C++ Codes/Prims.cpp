class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        //adj[i][j] { u , wt } => i->u (wt)
        
        vector<int> visited(V,false);
        vector<int> key(V, INT_MAX);
        vector<int> pred(V,-1);
        
        int sum=0;
        pred[0]=-1;
        key[0]=0;
        
        //pq = {v,key[v]}
        priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > pq;
        
        pq.push({0,0});
        
        while(!pq.empty()){
            
            auto u=pq.top();
            pq.pop();
            visited[u.first] = true;
            sum+=u.second;
            
            for(auto it: adj[u.first]){
                //it is [adj node, wt]
                int v=it[0], wt=it[1];
                if(!visited[v] && wt < key[v]){
                    key[v] = wt;
                    pred[v] = u.first;
                    pq.push({v, key[v]});
                }
            }
            
        }
        
        return sum;
    }
};