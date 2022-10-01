class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n=edges.size();
        unordered_map<int,int>mpp;
        for(int i=0; i < n; i++){
            mpp[edges[i][0]]++;
            mpp[edges[i][1]]++;
        }
         for(auto j:mpp){
             if(j.second == n){
                 return j.first;
             }
         }
        return -1;
    }
};
