stack<TreeNode*> st;
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode* x = st.top();
        st.pop();
        pushAll(x->right);
        return x->val;

    }
    
    bool hasNext() {
        return !st.empty();
    }
    
    void pushAll(TreeNode* root){
        while(root){
            st.push(root);
            root=root->left;
        }
    }