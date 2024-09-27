#include <bits/stdc++.h>
using namespace std;
struct node 
{ 
    int key; 
    struct node *left, *right; 
}; 
  
// A utility function to create a new BST node 
struct node *newNode(int item) 
{ 
    struct node *temp =  (struct node *)malloc(sizeof(struct node)); 
    temp->key = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
/* A utility function to insert a new node with given key in BST */
struct node* insert(struct node* node, int key) 
{ 
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key); 
  
    /* Otherwise, recur down the tree */
    if (key < node->key) 
        node->left  = insert(node->left, key); 
    else if (key > node->key) 
        node->right = insert(node->right, key);    
  
    /* return the (unchanged) node pointer */
    return node; 
} 
/* This function traverse the skewed binary tree and 
   stores its nodes pointers in vector nodes[] */
void storeBSTNodes(struct node* root, vector<struct node*> &nodes) 
{ 
    // Base case 
    if (root==NULL) 
        return; 
  
    // Store nodes in Inorder (which is sorted 
    // order for BST) 
    storeBSTNodes(root->left, nodes); 
    nodes.push_back(root); 
    storeBSTNodes(root->right, nodes); 
} 
  
/* Recursive function to construct binary tree */

  
// This functions find Kth Minimum Element in BST
int findKthMinimumElement(struct node* root,int k) 
{ 
    // Store nodes of given BST in sorted order 
    vector<struct node*> nodes; 
    storeBSTNodes(root, nodes); 
 
    return nodes[k-1]->key;
} 

// Driver Program to test above functions 
int main() 
{ 
    int k =3;
    struct node *root = NULL; 
    root = insert(root, 6); 
    insert(root, 4); 
    insert(root, 5); 
    insert(root, 3); 
    insert(root, 8); 
    insert(root, 9); 
    cout<<"The "<<k<<" th smallest element in Binary search tree is "<<findKthMinimumElement(root,k);
} 
