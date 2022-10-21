/******************************************************************************
BINARY TREE TRANSVERSAL
                       1
                     /  \
                    2    3
                  / \   / \
                 4  5   6  7 
1. Preorder Traversal: Write the value of present root then go onto root's left subtree(left node)
                       then go to rifht subtree.
                       Preorder traversal value: 1, 2, 4, 5, 3, 6, 7                   
2. Inoder Traversal: Travel the left subtree of a root first (travelling n writing values), then
                     travel the root n then the right subtree of the root.
                     Inorder traversal value: 4, 2, 5, 1, 6, 3, 7                    
3. Postorder Traversal: Travel the left subtree of a root first (travelling n writing values), then
                        travel the right subtree of the root n then the root.  
                        Postorder traversal value: 4, 5, 2, 6, 7, 3, 1                       
*******************************************************************************/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data ;
    struct Node* right ;
    struct Node* left ;
    
    Node(int val)
    {
        data = val;
        left = NULL ;
        right = NULL;
    }
};
// PREORDER funcn to print
void preorder(struct Node* root)
{
    if(root == NULL)                  // we don't have to print anything we just have to return
    return;                                            
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);           
}
// INORDER funcn to print
void inorder(struct Node* root)
{
    if(root == NULL)                  // we don't have to print anything we just have to return
    return;                                            
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);           
}
// POSTRDER funcn to print
void postorder(struct Node* root)
{
    if(root == NULL)                  // we don't have to print anything we just have to return
    return;                                            
    postorder(root->left);
    postorder(root->right); 
    cout << root->data << " ";
}
int main()
{
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    preorder(root);
    cout << endl ;
    inorder(root);
    cout << endl ;
    postorder(root);
    cout << endl ;
    return 0;
}
