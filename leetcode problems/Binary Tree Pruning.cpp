class Solution
{
public:
    int solve(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        if (root->left == NULL && root->right == NULL)
        {
            if (root->val == 0)
                return 0;
            else
                return 1;
        }

        int left = solve(root->left);
        int right = solve(root->right);

        if (left == 0)
            root->left = NULL;
        if (right == 0)
            root->right = NULL;

        return left + right + (root->val == 0 ? 0 : 1);
    }

    TreeNode *pruneTree(TreeNode *root)
    {

        if (solve(root) == NULL)
            return 0;

        return root;
    }
};