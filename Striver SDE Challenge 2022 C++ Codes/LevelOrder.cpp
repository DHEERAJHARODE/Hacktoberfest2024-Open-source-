vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> levelorder;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int level_size=q.size();
            vector<int> temp;
            for(int i=0;i<level_size;i++){
                TreeNode* curr=q.front(); //taking the first value in the q
                temp.push_back(curr->val); //adding it in ans
                q.pop();
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            levelorder.push_back(temp);
        }
        return levelorder;
    }