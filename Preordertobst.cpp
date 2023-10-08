/*
Problem Statement:- Given an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree), construct the tree and return its root.

Time Complexity:-O(nlogn) average case
Space Complexity:-O(n) worst case(in case of skew-tree)
                  O(h) average case (h is height of BST)

Approach:-
1) Create a root node with first value of given vector or array.
2) Call a function for inserting value in Bst
3)In insert function with parametres root and value ,create a new node with val
4) If root is NULL return node
5)Otherwise,If val is greater than root->value, call the same insert function for right subtree.
6) else, call the function for left subtree.
7)return root.
*/







class Solution {
public:
 TreeNode* insertIntoBST(TreeNode* root, int val) {

       TreeNode* node=new TreeNode(val);
       if(root==NULL)
       {
           return node;
       } 

       if(val>root->val)
       {
         root->right= insertIntoBST( root->right, val); 
       }
       if(val<root->val)
       {
           root->left=insertIntoBST(root->left, val);
       }
       return root;
        
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n=preorder.size();
        TreeNode* temp=new  TreeNode(preorder[0]);
        TreeNode* ptr=temp;

        for(int i=1;i<n;i++)
        {
            
            insertIntoBST( ptr, preorder[i]);
            
        }
        return temp;
        
    }
};
