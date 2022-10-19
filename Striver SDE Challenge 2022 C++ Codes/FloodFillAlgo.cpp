vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oldColor = image[sr][sc];
        if(oldColor!=newColor) dfs(image, sr, sc, oldColor, newColor);
        return image;
    }
    
    void dfs(vector<vector<int>>& image, int sr, int sc, int oldColor, int newColor){
        int c=image[0].size(), r=image.size();
        int currentColor = image[sr][sc];
        if(currentColor == oldColor){
            image[sr][sc] = newColor;
            if(sr+1 < r) dfs(image, sr+1,sc,oldColor,newColor);
            if(sc+1 < c) dfs(image, sr,sc+1,oldColor,newColor);
            if(sr-1 >= 0) dfs(image, sr-1,sc,oldColor,newColor);
            if(sc-1 >= 0) dfs(image, sr,sc-1,oldColor,newColor);
        }
    }