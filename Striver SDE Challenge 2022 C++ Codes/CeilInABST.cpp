int findCeil(BinaryTreeNode<int> *node, int x){
    int succ=-1;
    while(node){
        if(node->data < x) node=node->right;
        else{
            succ = node->data;
            node=node->left;
        }
    }
    return succ;
}