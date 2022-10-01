class Solution
{
public:
    TreeNode *bst(vector<int> &nums, int left, int right)
    {
        if (left > right)
            return NULL;
        int mid = left + (right - left) / 2;
        TreeNode *node = new TreeNode(nums[mid]);
        node->left = bst(nums, left, mid - 1);
        node->right = bst(nums, mid + 1, right);
        return node;
    }

    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        if (nums.empty())
            return NULL;

        return bst(nums, 0, nums.size() - 1);
    }
};