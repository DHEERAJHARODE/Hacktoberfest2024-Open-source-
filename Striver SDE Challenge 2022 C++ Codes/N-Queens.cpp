bool isSafe(int row,int col,int n,vector<int> tmp){
        // we check only upr,lwr diagonal and the same row and not the same col as we r trying for each col one by one
        int r=row,c=col;
        while(r >= 0 && c >= 0){ //upper left diagonal
            if(tmp[r][c]=='Q') return false;
            r--;
            c--;
        }
        r=row,c=col;
        while(c >= 0){//same row
            if(tmp[r][c]=='Q') return false;
            c--;
        }
        while(r < n && c >= 0){ //upper left diagonal
            if(tmp[r][c]=='Q') return false;
            r++;
            c--;
        }
        return true;
    }
    void nqn(int col, int n, vector<string> &tmp, vector<vector<string>> &ans){
        if(col==n){
            ans.push_back(tmp);
            return;
        }
        for(int row=0;row<n;row++){
            if(isSafe(row,col,n,tmp)){
                tmp[row][col]='Q';
                nqn(ind+1,n,tmp,ans);
                tmp[row][col]='.'; 
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> tmp(n);
        string s(n,'.');
        for(int i=0;i<n;i++)
            tmp[i]=s;
        nqn(0,n,tmp,ans);
        return ans;
    }