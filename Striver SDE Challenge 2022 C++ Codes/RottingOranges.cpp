int orangesRotting(vector<vector<int>>& grid) {
        //mins for ans
        //tot to check total oranges to rot and verify at end if posible to rot all
        //count for keeping count of oranges in q
        int m=grid.size(),n=grid[0].size(),count=0,tot=0,mins=0;
        queue<pair<int,int>> q;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2) q.push({i,j});
                if(grid[i][j]!=0) tot++;
            }
        }
        
        int dx[4]={0,0,-1,+1};
        int dy[4]={-1,+1,0,0};
        
        while(!q.empty()){
            int k=q.size();
            count += k;
            while(k--){
                int x=q.front().first, y=q.front().second; //pos of rotten orange
                q.pop();
                for(int i=0;i<4;i++){
                    int nx=x+dx[i],ny=y+dy[i];//next pos to check
                    if(nx<0 || nx>=m || ny<0 || ny>=n || grid[nx][ny]!=1) continue;
                    grid[nx][ny]=2;
                    q.push({nx,ny});
                }
            }
            if(!q.empty()) mins++;         
        }
        return tot == count ? mins: -1;
    }