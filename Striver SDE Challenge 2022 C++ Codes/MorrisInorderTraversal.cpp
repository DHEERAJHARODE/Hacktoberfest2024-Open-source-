vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        TreeNode* cur = root;
        while(cur) {
            if(!cur->left){
                //this is the leftmost node, push it
                inorder.push_back(cur->val);
                //cur now goes back to the root node this sub tree using                   //the thread
                cur=cur->right;
            }
            else{
                TreeNode* next=cur->left;
                while(next->right and next->right != cur)
                    next=next->right;
                //while break due to one of the mentioned conditions
                if(!next->right){
                    //estb thread to its root
                    next->right=cur;
                    //now move cur to next left
                    cur=cur->left;
                }
                //there is a thread=>we have already visited the current
                //cur
                else{
                    next->right=NULL;
                    inorder.push_back(cur->val);
                    //so the cur moves to right and not left
                    cur=cur->right;
                }
            }
        }
        return inorder;
    }