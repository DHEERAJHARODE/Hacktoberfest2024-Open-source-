bool check(TreeNode* root, long lb, long ub) {
        if(!root) return true;
        if(root->val <= lb or root->val >= ub) return false;
        return check(root->left, lb, root->val) and check(root->right, root->val, ub);
    }
    
    bool isValidBST(TreeNode* root){
        return check(root, LONG_MIN, LONG_MAX);
    }