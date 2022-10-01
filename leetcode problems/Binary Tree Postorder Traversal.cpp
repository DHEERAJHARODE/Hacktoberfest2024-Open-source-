class Solution
{
public:
    void solve(TreeNode *node, vector<int> &ans)
    {
        if (node == NULL)
            return;

        solve(node->left, ans);
        solve(node->right, ans);
        ans.push_back(node->val);
    }

    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        solve(root, ans);
        return ans;
    }
};