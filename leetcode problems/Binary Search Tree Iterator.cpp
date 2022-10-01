// using vector
class BSTIterator {
public:
    vector<int> v;
    int index=0;
    void inorder(TreeNode* node)
    {
        if(!node) return;
        
        inorder(node->left);
        v.push_back(node->val);
        inorder(node->right);
    }
    BSTIterator(TreeNode* root) {
        inorder(root);
        
    }
    
    int next() {
      return v[index++];
    }
    
    bool hasNext() {
        return index<v.size();
    }
};


// using stack 
class BSTIterator {
public:
    stack<TreeNode* > s;
    void pushAll(TreeNode* node)
    {
        for(; node != NULL; s.push(node), node=node->left);
    }
    BSTIterator(TreeNode* root) {
        pushAll(root);
        
    }
    
    int next() {
        TreeNode* tempNode = s.top();
        s.pop();
        pushAll(tempNode->right);
        return tempNode->val;
    }
    
    bool hasNext() {
        return !s.empty();
    }
};
