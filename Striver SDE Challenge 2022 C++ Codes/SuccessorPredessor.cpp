int succ(BinaryTreeNode<int>* root, int key){
    int suc=-1;
    while(root){
        if(root->data <= key)
            root=root->right;
        else{
            suc=root->data;
            root=root->left;
        }
    }
    return suc;
}

int pred(BinaryTreeNode<int>* root, int key){
    int pre=-1;
    while(root){
        if(root->data >= key)
            root=root->left;
        else{
            pre=root->data;
            root=root->right;
        }
    }
    return pre;
}

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    return {pred(root,key),succ(root,key)};
}
