//https://leetcode.com/problems/longest-consecutive-sequence/
//https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1
//https://www.codingninjas.com/codestudio/problems/759408/
//https://youtu.be/qgizvmgeyUM
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
//  T=O(nlogn)   S=O(1)
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0 ){
            return 0;
        }
        sort(nums.begin(),nums.end());
        int max_count=1;
        int count=1;

        for(int i=1;i<nums.size();i++){ 
            if(nums[i]==nums[i-1]+1){
                count++;
            }
            else if(nums[i]!=nums[i-1]){
                count=1;
            }
            if(count>max_count){
                max_count=count;
            }
        }
        return max_count;
}
//  T=O(n)   S=O(n)
    int longestConsecutive2(vector<int>& nums) {
        set<int> set;
        int max_count=1;
        for(int i=0;i<nums.size();i++){
            set.insert(nums[i]);
        }
        for(int i=0;i<nums.size();i++){
            if(set.count(nums[i]-1)){
                // Do Nothing
            }
            else{
                int currentNum = nums[i];
                int count = 1;
                while (set.count(currentNum + 1)) {
                    currentNum += 1;
                    count += 1;
                }
                max_count=max(max_count,count);
            }
        }
        return max_count;
    }
};
int main(){
    vector<int> nums ={2,6,1,9,4,5,3};
    //Output =6{1,2,3,4,5,6}
    Solution obj;
    cout<<obj.longestConsecutive2(nums);
   return 0;
}