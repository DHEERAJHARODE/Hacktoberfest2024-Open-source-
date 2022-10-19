int func(TreeNode* root, int& maxi){
        if(!root) return 0;
        int lmax=max(0,func(root->left,maxi));
        int rmax=max(0,func(root->right,maxi));
        maxi = max(maxi, lmax+rmax+root->val);
        //below returns max of left and right childs of root
        return root->val+max(lmax,rmax);
    }
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        func(root,maxi);
        return maxi;
    }