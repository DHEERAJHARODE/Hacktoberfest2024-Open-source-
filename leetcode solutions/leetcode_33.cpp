class Solution
{
public:
    int BinarySearch(vector<int> &nums, int n, int target, int start, int end)
    {
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] < target)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        return -1;
    }

    int getPivotElem(vector<int> arr, int n)
    {
        int start = 0;
        int end = n - 1;
        while (start < end)
        {
            int mid = start + (end - start) / 2;
            if (arr[mid] >= arr[0])
            {
                start = mid + 1;
            }
            else
            {
                end = mid;
            }
            mid = start + (end - start) / 2;
        }
        return start;
    }

    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int k = getPivotElem(nums, n);
        if (nums[k] <= target && target <= nums[n - 1])
        {
            return BinarySearch(nums, n, target, k, n - 1);
        }
        else
        {
            return BinarySearch(nums, n, target, 0, k - 1);
        }
    }
};