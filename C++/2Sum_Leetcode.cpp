#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> numIndexMap;
        std::vector<int> result;
        
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            
            if (numIndexMap.find(complement) != numIndexMap.end()) {
                // If the complement exists in the map, we found a pair
                result.push_back(numIndexMap[complement]);
                result.push_back(i);
                break; // Since there is exactly one solution, we can exit early
            }
            
            numIndexMap[nums[i]] = i; // Store the current number and its index
        }
        
        return result;
    }
};
