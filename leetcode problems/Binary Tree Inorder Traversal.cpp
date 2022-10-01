class Solution
{
public:
    void solve(TreeNode *node, vector<int> &ans)
    {
        if (node == NULL)
            return;

        solve(node->left, ans);
        ans.push_back(node->val);
        solve(node->right, ans);
    }

    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        solve(root, ans);
        return ans;
    }
};