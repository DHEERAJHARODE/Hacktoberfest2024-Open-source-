bool isSymmetric(TreeNode* root) {
        return (!root || checker(root->left,root->right));
    }
    bool checker(TreeNode* cl, TreeNode* cr){
        if(!cl || !cr) return cr==cl;
        if(cl->val!=cr->val) return false;
        return (checker(cl->left,cr->right) && checker(cl->right,cr->left));
    }

// ITERATIVE
    bool isSymmetric(TreeNode* root){
        queue<TreeNode*>q;        
        q.push(root->left);
        q.push(root->right);
        while(!q.empty()){
            TreeNode* ln=q.front();
            q.pop();
            TreeNode* rn=q.front();
            q.pop();
            if(!ln and !rn) continue;
            if(ln and !rn or !ln and rn) return false;
            if(ln->val != rn->val) return false;
            q.push(ln->left); 
            q.push(rn->right);
            q.push(ln->right);
            q.push(rn->left);
        }
        return true;
    }