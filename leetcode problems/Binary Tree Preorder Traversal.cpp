class Solution
{
public:
    void solve(TreeNode *node, vector<int> &ans)
    {
        if (node == NULL)
            return;

        ans.push_back(node->val);
        solve(node->left, ans);
        solve(node->right, ans);
    }

    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        solve(root, ans);
        return ans;
    }
};