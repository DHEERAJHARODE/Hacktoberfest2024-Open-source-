#include<iostream>
using namespace std;

/* HacktoberFest 2022 
Tree Traversals Contribution by: Calladrus2k1
*/

struct TreeNode
{
    int key;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int k)
    {
        key = k;
        left = right = NULL;
    }
};

void Inorder(TreeNode* head){
    if (head == nullptr) return;
    Inorder(head->left);
    cout << head->val;
    Inorder(head->right);
}

void Preorder(TreeNode* head){
    if (head == nullptr) return;
    cout << head->val;
    Preorder(head->left);
    Preorder(head->right);
}

void Postorder(TreeNode* head){
    if (head == nullptr) return;
    Postorder(head->left);
    Postorder(head->right);
    cout << head->val;
}

int main()
{
    void Inorder(TreeNode* head);
    void Preorder(TreeNode* head);
    void Postorder(TreeNode* head);
    TreeNode *root = new TreeNode(10);
    TreeNode *Lchild = new TreeNode(20);
    TreeNode *Rchild = new TreeNode(30);
    TreeNode *LLchild = new TreeNode(40);
    root->left = Lchild;
    root->right = Rchild;
    Lchild->left = LLchild;
    Inorder(root);
}
