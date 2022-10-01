#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};


// Function to create the Binary Tree
struct TreeNode* create()
{
    int data;
    struct TreeNode* tree;
 
    // Dynamically allocating memory
    // for the tree-node
    tree = new TreeNode;
 
    cout << "\nEnter data to be inserted "
         << "or type -1 for no insertion : ";
 
    // Input from the user
    cin >> data;
 
    // Termination Condition
    if (data == -1)
        return nullptr;
 
    // Assign value from user into tree
    tree->val = data;
 
    // Recursively Call to create the
    // left and the right sub tree
    cout << "Enter left child of : "
         << data;
    tree->left = create();
 
    cout << "Enter right child of : "
         << data;
    tree->right = create();
 
    // Return the created Tree
    return tree;
}


    void preorder(TreeNode* node,int vertical,int level,map<int,map<int,multiset<int>>> &nodes){
        if(node == nullptr) return;
        
        nodes[vertical][level].insert(node->val);
        preorder(node->left,vertical-1,level+1,nodes);
        preorder(node->right,vertical+1,level+1,nodes);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> nodes;
        preorder(root,0,0,nodes);
        vector<vector<int>> ans;
        
        for(auto p:nodes){
            vector<int> col;
            for(auto q:p.second){
                col.insert(col.end(),q.second.begin(),q.second.end());
            }
            ans.push_back(col);
        }
        
        
        return ans;
    }


int main(){
    TreeNode *root = create();
    vector<vector<int>> ans = verticalTraversal(root);

    for(auto it:ans){
        for(auto itt: it){
            cout << itt << " ";
        }
        cout << endl;
    }
}