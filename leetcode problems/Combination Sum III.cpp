class Solution {
public:
    vector<vector<int>> result;
    
    void try_combn(vector<int>& combination, int k, int n, int start)
    {
        if(k == combination.size())
        {
            if(n==0)
            {
                result.push_back(combination);
                return;
            }             
        }
        
        for(int i=start; i<=9; i++)
            {
                combination.push_back(i);
                try_combn(combination, k, n-i, i+1);
                combination.pop_back();
            }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> combination;
        
        try_combn(combination, k, n, 1);
        return result;
    }
};