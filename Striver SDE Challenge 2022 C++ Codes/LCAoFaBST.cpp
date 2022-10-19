TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        if(p->val < root->val and q->val < root->val) return lowestCommonAncestor(root->left, p, q);
        if(p->val > root->val and q->val > root->val) return lowestCommonAncestor(root->right, p, q);
        return root;
    }