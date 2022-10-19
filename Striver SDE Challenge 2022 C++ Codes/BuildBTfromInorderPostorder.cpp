TreeNode* build(vector<int>& inorder, vector<int>& postorder,int inStart, int inEnd, int postStart, int postEnd, map<int,int>& inMap) {
        if(inStart>inEnd || postStart>postEnd) return NULL;
        int pivot=inMap[postorder[postEnd]];
        int inLeft=pivot-inStart;
        TreeNode* cur = new TreeNode(postorder[postEnd]);
        cur->left=build(inorder,postorder,inStart,pivot-1,postStart,postStart+inLeft-1,inMap);//-is
        cur->right=build(inorder,postorder,pivot+1,inEnd,postStart+inLeft,postEnd-1,inMap);//-is
        return cur;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> inMap;
        for(int i=0;i<inorder.size();i++)
            inMap[inorder[i]]=i;
        return build(inorder,postorder,0,inorder.size()-1,0,postorder.size()-1,inMap);
    }