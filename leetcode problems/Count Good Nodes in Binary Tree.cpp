class Solution
{
public:
    void check(TreeNode *node, int &count, int max)
    {
        if (node == NULL)
            return;

        if (node->val >= max)
        {
            count++;
            max = node->val;
        }

        check(node->left, count, max);
        check(node->right, count, max);
    }

    int goodNodes(TreeNode *root)
    {

        int count = 0;
        if (!root)
            return count;

        check(root, count, root->val);

        return count;
    }
};