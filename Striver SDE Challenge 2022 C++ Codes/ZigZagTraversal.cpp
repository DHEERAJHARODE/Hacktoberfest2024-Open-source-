vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        bool l2r=true;
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            vector<int> temp(sz);
            for(int i=0;i<sz;i++){
                TreeNode* node = q.front();
                q.pop();
                int t=node->val;
                if(l2r) temp[i]=t;
                else temp[sz-1-i]=t;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans.push_back(temp);
            l2r=!l2r;
        }
        return ans;
    }