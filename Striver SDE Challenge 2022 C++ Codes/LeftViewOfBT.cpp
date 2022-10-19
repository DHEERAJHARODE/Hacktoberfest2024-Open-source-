void leftView(Node *root, int level, vector<int> &ans){
    if(!root) return;
    if(ans.size()==level) ans.push_back(root->data);
    leftView(root->left,level+1,ans);
    leftView(root->right,level+1,ans);
}
//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
   vector<int> ans;
   leftView(root, 0, ans);
   return ans;
}