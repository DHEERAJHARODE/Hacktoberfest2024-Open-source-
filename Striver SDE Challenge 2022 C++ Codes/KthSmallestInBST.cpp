int kthSmallest(TreeNode* root, int& k) {
        if(root){
            int l = kthSmallest(root->left,k);
            if(l) return l;

            k--;
            if(k==0) return root->val;

            return kthSmallest(root->right,k);
        }
        return 0;
    }