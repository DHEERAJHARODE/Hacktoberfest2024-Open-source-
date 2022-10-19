bool allowed(int node, int color[], vector<vector<int>> &mat, int col){
    for(int i=0;i<mat.size();i++){
        if(i!=node and mat[node][i]==1 and color[i]==col) return false;
    }
    return true;
}

bool gc(int node, int color[], vector<vector<int>> &mat, int m){
    if(node==mat.size()) return true;
    for(int i=1;i<=m;i++){
        if(allowed(node,color,mat,i)){
            color[node]=i;
            if(gc(node+1,color,mat,m)) return true;
            color[node]=0;
        }
    }
    return false;
}

string graphColoring(vector<vector<int>> &mat, int m) {
    int color[m]={0};
    if(gc(0,color,mat,m)) return "YES";
    else return "NO";
}