class Solution
{
public:
    void find(int id, vector<int> &candidates, int target, vector<vector<int>> &ans, vector<int> &temp)
    {

        if (target == 0)
        {
            ans.push_back(temp);
            return;
        }

        for (int i = id; i < candidates.size(); i++)
        {
            if (i > id && candidates[i] == candidates[i - 1])
                continue;
            if (candidates[i] > target)
                break;
            temp.push_back(candidates[i]);
            find(i + 1, candidates, target - candidates[i], ans, temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {

        vector<vector<int>> ans;
        vector<int> temp;

        sort(candidates.begin(), candidates.end());

        find(0, candidates, target, ans, temp);

        return ans;
    }
};