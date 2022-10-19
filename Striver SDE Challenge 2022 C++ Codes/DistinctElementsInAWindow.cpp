vector<int> Solution::dNums(vector<int> &A, int k) {
    
    if(k>A.size()) return {};
    
    vector<int> ans;
    unordered_map<int,int> umap;
    
    for(int i=0;i<k;i++) umap[A[i]]++;
    ans.push_back(umap.size());
    
    for(int i=k;i<A.size();i++){
        if(umap[A[i-k]] != 1) umap[A[i-k]]--;
        else umap.erase(A[i-k]);
        umap[A[i]]++;
        ans.push_back(umap.size());
    }
    
    return ans;
}