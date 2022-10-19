TreeNode* searchBST(TreeNode* root, int val) {
        while(root){
            int t=root->val;
            if(t == val) return root;
            else if(val > t) root=root->right;
            else root=root->left;
        }
        return root;
    }