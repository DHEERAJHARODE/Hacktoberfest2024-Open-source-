class Solution
{
public:
    string solve(TreeNode *root)
    {
        if (root == NULL)
            return "";

        if (root->left == NULL && root->right == NULL)
            return to_string(root->val) + "";
        if (root->right == NULL)
            return to_string(root->val) + "(" + solve(root->left) + ")";
        return to_string(root->val) + "(" + solve(root->left) + ")" + "(" + solve(root->right) + ")";
    }

    string tree2str(TreeNode *root)
    {
        return solve(root);
    }
};