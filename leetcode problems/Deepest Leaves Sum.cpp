class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        
        queue<TreeNode *> q;
        int sum=0;
        
        q.push(root);
        
        while(!q.empty())
        {
            int n = q.size();
            
            for(int i=0; i<n; i++)
            {
                 TreeNode * temp = q.front();
                q.pop();
                
                sum += temp->val;
                
                if(temp->left)
                {
                    q.push(temp->left);
                }
                
                if(temp->right)
                {
                    q.push(temp->right);
                }
            }
            
            if(!q.empty()) sum=0;
        }
        return sum;
    }
};