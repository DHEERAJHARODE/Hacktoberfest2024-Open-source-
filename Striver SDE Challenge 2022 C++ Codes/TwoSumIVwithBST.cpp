class BSTIterator {
public:
    stack<TreeNode*> st;
    bool rev= true;
    BSTIterator(TreeNode* root, bool isrev) {
        rev=isrev;
        pushAll(root);
    }
    
    int next(){
        TreeNode* x = st.top();
        st.pop();
        //push all right nodes as lefts are pushed
        if(!rev) pushAll(x->right);
        //push all left nodes as right are pushed
        else pushAll(x->left);
        return x->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
    
    void pushAll(TreeNode* root){
        while(root){
            st.push(root);
            //push all left nodes from root
            if(!rev) root=root->left;
            //push all right nodes from root
            else root=root->right;
        }
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        //inorder of bst is a sorted arr
        BSTIterator l(root,false);
        BSTIterator r(root,true);
        //i and j point to 1st and last index of tree
        int i = l.next();
        int j = r.next();
        //apply bs
        while(i<j){
            if(i+j==k) return true;
            else if(i+j<k) i=l.next();
            else j=r.next();
        }
        return false;
    }
};