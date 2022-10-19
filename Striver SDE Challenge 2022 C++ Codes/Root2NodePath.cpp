bool path(TreeNode* A, int B, vector<int> &ans){
    if(A==NULL) return false;
    ans.push_back(A->val);
    if(A->val==B) return true;
    if(path(A->left,B,ans) || path(A->right,B,ans)) return true;
    else{
        ans.pop_back();
        return false;
    }
}
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> ans;
    path(A,B,ans);
    return ans;
}