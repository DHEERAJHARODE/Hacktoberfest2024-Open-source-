vector<int> postorderTraversal(TreeNode* root) {
        // if(!root) return {};
        stack<TreeNode*> st;
        vector<int> postorder;
        TreeNode* curr=root;
        TreeNode* temp;
        while(curr || !st.empty()){
            if(curr){
                st.push(curr);
                curr=curr->left;
            }
            else{
                temp=st.top()->right;
                if(!temp){
                    temp=st.top();
                    st.pop();
                    postorder.push_back(temp->val);
                    while(!st.empty() && temp==st.top()->right){
                        temp=st.top();
                        st.pop();
                        postorder.push_back(temp->val);
                    }                  
                }
                else curr=temp;
            }
        }
        return postorder;
    }