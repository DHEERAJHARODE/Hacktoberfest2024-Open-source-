int drop(int floor, int eggs){
        //only 1 egg=>at worst we need to n moves (see eg 1)
        if(eggs==1) return floor;
        //only 1 or 0 floors=>that many moves
        if(floor==0 || floor==1) return floor;
        int ans = 1e9;
        for(int i=1;i<=floor;i++){
            //if break at this floor then breaks at every floor above,
            //so check for floors below
            int broke = drop(i-1, eggs-1);
            //if not break on this floor, then wont break at floors belwo as well
            //check for above floors
            int notbroke = drop(floor-i, eggs);
            //finding max moves
            int temp = 1+max(broke,notbroke);
            //finding min eggs
            ans = min(ans, temp);
        }
        return ans;
    }
    int superEggDrop(int k, int n) {
        return drop(n, k);
    }


int drop(int floor, int eggs, vector<vector<int>>& dp){
        //only 1 egg=>at worst we need to n moves (see eg 1)
        if(eggs==1) return floor;
        //only 1 or 0 floors=>that many moves
        if(floor==0 || floor==1) return floor;
        
        if(dp[floor][eggs]!=-1) return dp[floor][eggs];
        
        int ans = 1e9;
        for(int i=1;i<=floor;i++){
            //if break at this floor then breaks at every floor above,
            //so check for floors below
            int broke = drop(i-1, eggs-1, dp);
            //if not break on this floor, then wont break at floors belwo as well
            //check for above floors
            int notbroke = drop(floor-i, eggs, dp);
            //finding max moves
            int temp = 1+max(broke,notbroke);
            //finding min eggs
            ans = min(ans, temp);
        }
        return dp[floor][eggs] = ans;
    }
    
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        return drop(n, k, dp);
    }

//using BINARY SEARCH
int drop(int floor, int eggs, vector<vector<int>>& dp){
        //only 1 egg=>at worst we need to n moves (see eg 1)
        if(eggs==1) return floor;
        //only 1 or 0 floors=>that many moves
        if(floor==0 || floor==1) return floor;
        
        if(dp[floor][eggs]!=-1) return dp[floor][eggs];
        
        int ans = 1e9;
        int beg=1,end=floor;
        
        while(beg<=end){
            int mid=beg+(end-beg)/2;
            //if break at this floor then breaks at every floor above,
            //so check for floors below
            int left = drop(mid-1, eggs-1, dp);
            //if not break on this floor, then wont break at floors belwo as well
            //check for above floors
            int right = drop(floor-mid, eggs, dp);
            //finding max moves
            int temp = 1+max(left,right);
            
            if(left<right) beg=mid+1;
            else end=mid-1;
            //finding min eggs
            ans = min(ans, temp);
        }
        return dp[floor][eggs] = ans;
    }
     
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        return drop(n, k, dp);
    }

//DP
int superEggDrop(int k, int n) {
        if(n==1 || k==1) return n;
        
        //dp arr of dp[eggs][floor]
        vector<vector<int>> dp(k+1,vector<int>(n+1,0));
        
        //base cases
        for(int i=0;i<=k;i++){
            //eggs = 0/1 => moves = 0/1
            dp[i][0]=0;dp[i][1]=1;
        }
        for(int j=0;j<=n;j++){
            //floor = 0/1 => moves = 0/n           
            dp[0][j]=0;dp[1][j]=j;
        }
        
        for(int i=2;i<=k;i++){
            for(int j=2;j<=n;j++){
                int ans=1e9,beg=1,end=j;
                while(beg<=end){
                    int mid=beg+(end-beg)/2;
                    //if break at this floor then breaks at every floor above,
                    //so check for floors below
                    int left = dp[i-1][mid-1];
                    //if not break on this floor, then wont break at floors belwo as well
                    //check for above floors
                    int right = dp[i][j-mid];
                    //finding max moves
                    int temp = 1+max(left,right);

                    if(left<right) beg=mid+1;
                    else end=mid-1;
                    //finding min eggs
                    ans = min(ans, temp);
                }
                dp[i][j] = ans;
            }
        }
        return dp[k][n];
    }