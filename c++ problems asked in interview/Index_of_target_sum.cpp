// This program find the index of the two number in the array so that the sum meet the target number given by the user

#include <iostream>   // declaring header files
#include <vector>
#include <unordered_map>

std::vector<int> twoSum(std::vector<int>& nums, int target) {  //vector is used to store the input number
    std::unordered_map<int, int> numToIndex;  // unordered is used to efficiently store and manage a mapping between the elements

    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];

        if (numToIndex.find(complement) != numToIndex.end()) {
            return { numToIndex[complement], i };
        }

        numToIndex[nums[i]] = i;
    }

    return {}; // No result found
}

int main() {
    std::vector<int> nums = {32, 7, 21, 8};  // can use using namespace std as well
    int target;
    
    std::cout << "Enter the target sum: ";
    std::cin >> target;

    std::vector<int> result = twoSum(nums, target);

    if (!result.empty()) {
        std::cout << "Indices: " << result[0] << " and " << result[1] << std::endl;
    } else {
        std::cout << "No result found." << std::endl;
    }

    return 0;
}
