
#include <bits/stdc++.h>
using namespace std;

long long maxSubarraySum(int arr[], int n)
{
    long long maxi = LONG_MIN; // maximum sum
    long long sum = 0;

    int start = 0;
    int ansStart = -1, ansEnd = -1;
    for (int i = 0; i < n; i++)
    {

        if (sum == 0)
            start = i; // starting index

        sum += arr[i];

        if (sum > maxi)
        {
            maxi = sum;

            ansStart = start;
            ansEnd = i;
        }

        // If sum < 0: discard the sum calculated
        if (sum < 0)
        {
            sum = 0;
        }
    }

    // printing the subarray:
    cout << "The subarray is: [";
    for (int i = ansStart; i <= ansEnd; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "]\n";

    return maxi;
}

int main()
{
    int arr[] = {1, 2, 7, -4, 3, 2, -10, 9, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    long long maxSum = maxSubarraySum(arr, n);
    cout << "The maximum subarray sum is: " << maxSum << endl;
    return 0;
}