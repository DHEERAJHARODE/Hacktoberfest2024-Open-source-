bool isLeaf(TreeNode<int>* root){
    return !root->left and !root->right;
}

void addLeftNodes(TreeNode<int>* root, vector<int> &res){
    TreeNode<int>* cur=root->left;
    while(cur){
        if(!isLeaf(cur)) res.push_back(cur->data);
        if(cur->left) cur=cur->left;
        else cur=cur->right;
    }
}

void addLeafNodes(TreeNode<int>* root, vector<int> &res){
    if(isLeaf(root)) {
        res.push_back(root->data);
        return;
    }
    if(root->left) addLeafNodes(root->left, res);
    if(root->right) addLeafNodes(root->right, res);
}

void addRightNodes(TreeNode<int>* root, vector<int> &res){
    TreeNode<int>* cur=root->right;
    vector<int> temp;
    while(cur){
        if(!isLeaf(cur)) temp.push_back(cur->data);
        if(cur->right) cur=cur->right;
        else cur=cur->left;
    }
    for(int i=temp.size()-1;i>=0;i--)
        res.push_back(temp[i]);
}

vector<int> traverseBoundary(TreeNode<int>* root){
    vector<int> res;
    if(!root) return {};
    if(!isLeaf(root)) res.push_back(root->data);
    addLeftNodes(root,res);
    addLeafNodes(root,res);
    addRightNodes(root,res);
    return res;
}