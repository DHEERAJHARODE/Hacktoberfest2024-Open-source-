TreeNode* build(vector<int>& preorder, int& i, int ub){
        if(i==preorder.size() or preorder[i]>ub) return NULL; //array end or value cant be placed as child
        TreeNode* tree=new TreeNode(preorder[i++]);
        //for the left subtree, the node val is the ub
        tree->left = build(preorder, i, tree->val);
        //for the right subtree, the ub is the ub asn this val is > than node val so it checks if it is <
        //ub for the main tree
        tree->right = build(preorder, i, ub);
        return tree;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        //O(N X N) soln
        // stack<TreeNode*> st;
        // TreeNode* tree=new TreeNode(preorder[0]);
        // st.push(tree);
        // for(int i=1;i<preorder.size();i++){
        //     TreeNode* node = new TreeNode(preorder[i]);
        //     if(preorder[i]<st.top()->val){
        //         st.top()->left = node;
        //         st.push(node);
        //     }
        //     else{
        //         TreeNode* temp;
        //         while(!st.empty() and st.top()->val < preorder[i]){
        //             temp = st.top();
        //             st.pop();
        //         }
        //         temp->right=node;
        //         st.push(node);
        //     }
        // }
        // return tree;
        
        //O(N) soln
        int i=0;
        return build(preorder, i, INT_MAX);
    }