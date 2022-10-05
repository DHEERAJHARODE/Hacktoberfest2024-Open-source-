// Problem-  find a continuous sub-array which comes first and  adds to a given number S.
/*
Sliding Window Technique
--> Assign two pointers  front for end index and back for starting index of required subarray
--> A variable sum stores the sum of the variable window
--> If sum is equal to the given sum s then push_back the starting and end index of the subarray in vector v and return
--> if sum is greater than the given sum s then remove element at index back from sum and move the back pointer ahead 
--> If sum is less than the given sum s move front pointer ahead and include the element in the sum
*/
#include <iostream>
#include <vector>

using namespace std;

vector<int> subarraySum(int arr[], int n, int s)
{
    // Your code
    vector<int> v;
    int back = 0, front = 1;
    int sum = arr[0];

    while (front < n + 1)
    {
        if (sum == s)
        {
            v.push_back(back + 1);
            v.push_back(front);
            return v;
        }

        if (sum > s)
        {
            sum -= arr[back];
            back++;
        }
        else
            sum += arr[front++];
    }
    v.push_back(-1);
    return v;
}

int main()
{
    // n is the number of elements in the array
    //  s is the given sum of subarray
    int n, s;
    cin >> n >> s;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> ans;
    ans = subarraySum(arr, n, s);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    return 0;
}