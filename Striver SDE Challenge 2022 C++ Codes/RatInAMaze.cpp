class Solution{
    public:
    void rat(int r, int c, string tmp, vector<string> &ans, vector<vector<int>> &m, int n, vector<vector<int>> &visited){
        
        if(r==n-1 && c==n-1) {
            ans.push_back(tmp);
            return;
        }
        
        if(r+1<n && !visited[r+1][c] && m[r+1][c]==1){
            tmp+='D';
            visited[r][c]=1;
            rat(r+1,c,tmp,ans,m,n,visited);
            visited[r][c]=0;
            tmp.pop_back();
        }
        
        if(r-1>=0 && !visited[r-1][c] && m[r-1][c]==1){
            tmp+='U';
            visited[r][c]=1;
            rat(r-1,c,tmp,ans,m,n,visited);
            visited[r][c]=0;
            tmp.pop_back();
        }
        
        if(c+1<n && !visited[r][c+1] && m[r][c+1]==1){
            tmp+='R';
            visited[r][c]=1;
            rat(r,c+1,tmp,ans,m,n,visited);
            visited[r][c]=0;
            tmp.pop_back();
        }
        
        if(c-1>=0 && !visited[r][c-1] && m[r][c-1]==1){
            tmp+='L';
            visited[r][c]=1;
            rat(r,c-1,tmp,ans,m,n,visited);
            visited[r][c]=0;
            tmp.pop_back();
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        vector<vector<int>> visited(n,vector<int>(n,0));
        if(m[0][0]==1) rat(0,0,"",ans,m,n,visited);
        return ans;
    }
};