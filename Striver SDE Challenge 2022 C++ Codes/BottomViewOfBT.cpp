vector <int> bottomView(Node *root) {
        map<int, Node *> temp;//col,node
        queue<pair<Node *, int>> q; //node, col
        q.push({root,0});
        while(!q.empty()){
            auto p=q.front();
            Node *node=p.first;
            int x=p.second;
            temp[x]=node;
            q.pop();
            if(node->left) q.push({node->left, x-1});
            if(node->right) q.push({node->right, x+1});
        }
        vector<int> ans;
        for(auto p:temp)
            ans.push_back(p.second->data);
        return ans;
    }