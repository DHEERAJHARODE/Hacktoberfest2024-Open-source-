#include <iostream>  
using namespace std;  
struct node {  
    int element;  
    struct node* left;  
    struct node* right;  
};  

struct node* createNode(int val)  
{  
    struct node* Node = (struct node*)malloc(sizeof(struct node));  
    Node->element = val;  
    Node->left = NULL;  
    Node->right = NULL;  
    return (Node);  
}  
void traverseInorder(struct node* root)  
{  
    if (root == NULL)  
        return;  
    traverseInorder(root->left);  
    cout<<" "<<root->element<<" ";  
    traverseInorder(root->right);  
}  
int main()  
{  
    struct node* root = createNode(39);  
    root->left = createNode(29);  
    root->right = createNode(49);  
    root->left->left = createNode(24);  
    root->left->right = createNode(34);  
    root->left->left->left = createNode(14);  
    root->left->left->right = createNode(27);  
    root->right->left = createNode(44);  
    root->right->right = createNode(59);  
    root->right->right->left = createNode(54);  
    root->right->right->right = createNode(69);      
    cout<<"\n The Inorder traversal of given binary tree is -\n";  
    traverseInorder(root);  
    return 0;  
}  
