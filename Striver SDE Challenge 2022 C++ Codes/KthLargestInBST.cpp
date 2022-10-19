TreeNode<int>* kthlargest(TreeNode<int>* root, int& k)
{
    if(root==NULL)
    return NULL;
    
    TreeNode<int>* right=kthlargest(root->right,k);
    if(right!=NULL)
    return right;
    k--;
    
    if(k==0)
    return root;
    
    return kthlargest(root->left,k);
}

int KthLargestNumber(TreeNode<int>* root, int k) 
{
    TreeNode<int>* ans = kthlargest(root,k);
    if(ans) return ans->data;
    else return -1;
}
