void dfs(int i,int j,vector<vector<char>>& grid,int n,int m){
        if(i>=n or j>=m or i<0 or j<0 or grid[i][j]!='1') return;
        grid[i][j]='2';
        dfs(i+1,j,grid,n,m);
        dfs(i-1,j,grid,n,m);
        dfs(i,j+1,grid,n,m);
        dfs(i,j-1,grid,n,m);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int cnt=0;
        int n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1') {
                    dfs(i,j,grid,n,m);
                    cnt++;
                }
            }
        }
        return cnt;
    }