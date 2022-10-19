TreeNode* invertTree(TreeNode* root) {
        //DONT UNDERSTAND ITERATIVE
        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty()) {
            TreeNode* p = stk.top();
            stk.pop();
            if(p) {
                stk.push(p->left);
                stk.push(p->right);
                TreeNode* temp;
                temp = p->left;
                p->left = p->right;
                p->right = temp;
            }
        }
        return root;
        
        //RECURSIVE
        if(root) {
            invertTree(root->left);
            invertTree(root->right);
            swap(root->left, root->right);
        }
        return root;
    }