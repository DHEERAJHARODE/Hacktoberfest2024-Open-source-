vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        if (!root /*NULL root*/) return preorder;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            root=st.top();
            st.pop();
            preorder.push_back(root->val);
            if(root->right /*exits*/) st.push(root->right);
            if(root->left /*exits*/) st.push(root->left);
        }
        return preorder;
    }