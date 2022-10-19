TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)  {
        if(!root or root == p or root == q) return root;
        
        TreeNode* lt=lowestCommonAncestor(root->left,p,q);
        TreeNode* rt=lowestCommonAncestor(root->right,p,q);
        
        if(!lt) return rt;
        else if(!rt) return lt;
        else return root;
    }