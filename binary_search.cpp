#include <iostream>
#include <vector>

int binarySearch(const std::vector<int>& sortedArray, int target) {
    int left = 0;
    int right = sortedArray.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if the target is present at the middle
        if (sortedArray[mid] == target) {
            return mid;
        }

        // If the target is greater, ignore left half
        if (sortedArray[mid] < target) {
            left = mid + 1;
        }
        // If the target is smaller, ignore right half
        else {
            right = mid - 1;
        }
    }

    // If the target is not found in the array
    return -1;
}

int main() {
    std::vector<int> sortedArray = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int target = 10;

    int result = binarySearch(sortedArray, target);

    if (result != -1) {
        std::cout << "Element found at index: " << result << std::endl;
    } else {
        std::cout << "Element not found in the array." << std::endl;
    }

    return 0;
}
