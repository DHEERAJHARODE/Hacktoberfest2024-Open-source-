#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxSubArraySum(const vector<int>& arr) {
    int max_current = arr[0];
    int max_global = arr[0];

    for (size_t i = 1; i < arr.size(); i++) {
        max_current = max(arr[i], max_current + arr[i]);
        if (max_current > max_global) {
            max_global = max_current;
        }
    }
    return max_global;
}

int main() {
    vector<int> arr;
    int n, element;

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> element;
        arr.push_back(element);
    }

    int max_sum = maxSubArraySum(arr);
    cout << "Maximum subarray sum is: " << max_sum << endl;

    return 0;
}
