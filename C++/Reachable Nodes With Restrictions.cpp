class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        unordered_set<int> nxt(restricted.begin(), restricted.end());
        
        vector<int> next[n];
        vector<int> alreadyVisited(n, false);
        for(auto e: edges) {
            next[e[0]].push_back(e[1]);
            next[e[1]].push_back(e[0]);
        }
        
        queue<int> q;
        q.push(0);
        alreadyVisited[0]=true;
        int ans = 1;
        
        while(!q.empty()){
            int u = q.front(); q.pop();
            
            
            for(auto v: next[u]) {
                if(alreadyVisited[v] == false && nxt.count(v) == 0) {
                    alreadyVisited[v] = true;
                    q.push(v);
                    ans++;
                    // cout<<v<<" ";
                }
            }
        }
        return ans;
    }
};
