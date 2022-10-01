class Solution
{
public:
    vector<double> averageOfLevels(TreeNode *root)
    {

        queue<TreeNode *> q;
        vector<double> ans;

        q.push(root);

        while (!q.empty())
        {
            double sum = 0;
            int n = q.size();

            for (int i = 0; i < n; i++)
            {
                TreeNode *node = q.front();

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);

                sum += node->val;

                q.pop();
            }
            ans.push_back(sum / n);
        }
        return ans;
    }
};