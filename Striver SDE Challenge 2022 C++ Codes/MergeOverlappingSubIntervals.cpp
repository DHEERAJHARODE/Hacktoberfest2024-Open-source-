#include <bits/stdc++.h> 
vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end());
    if(intervals.size()==1)
        return intervals;
    else{
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]>ans.back()[1])//chech with last int in ans so as to update it in else if this is false
                ans.push_back(intervals[i]);
            else
                ans.back()[1]=max(intervals[i][1],ans.back()[1]);//max pf current int & last int in ans
        }
        return ans;
    }
}