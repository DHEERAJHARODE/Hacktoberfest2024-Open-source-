void changeTree(BinaryTreeNode < int > * root) {
    if(!root) return;
    int child=0;
    if(root->left) child += root->left->data;
    if(root->right) child += root->right->data;
    if(child>=root->data) root->data=child;
    else{
        if(root->left) root->left->data=root->data;
        if(root->right) root->right->data=root->data;
    }
    //move left and right
    changeTree(root->left);
    changeTree(root->right);
    //Backtracking
    int tot=0;
    if(root->left) tot += root->left->data;
    if(root->right) tot += root->right->data;
    //update if parent node (then it'd have child(s))
    if(root->left or root->right) root->data=tot;
}  