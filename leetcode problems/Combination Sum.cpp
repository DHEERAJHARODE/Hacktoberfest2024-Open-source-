class Solution
{
public:
    void find(int id, vector<int> &candidates, int target, vector<vector<int>> &ans, vector<int> &temp)
    {
        if (id == candidates.size())
        {
            if (target == 0)
                ans.push_back(temp);
            return;
        }

        if (candidates[id] <= target)
        {
            temp.push_back(candidates[id]);
            find(id, candidates, target - candidates[id], ans, temp);
            temp.pop_back();
        }

        find(id + 1, candidates, target, ans, temp);
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {

        vector<vector<int>> ans;
        vector<int> temp;

        find(0, candidates, target, ans, temp);

        return ans;
    }
};