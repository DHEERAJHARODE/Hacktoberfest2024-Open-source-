if(!root) return 0;
int l=maxDepth(root->left);
int r=maxDepth(root->right);
return 1+(max(l,r));
