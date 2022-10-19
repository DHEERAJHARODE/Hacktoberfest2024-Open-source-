int floorInBST(TreeNode<int> * root, int X)
{
    int pred=-1;
    while(root){
        if(root->val > X) root=root->left;
        else{
            pred = root->val;
            root=root->right;
        }
    }
    return pred;
}