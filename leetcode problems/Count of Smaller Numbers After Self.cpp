// what i thought of
class Solution
{
public:
    vector<int> countSmaller(vector<int> &nums)
    {

        vector<int> count;

        for (int i = 0; i < nums.size(); i++)
        {
            int c = 0;
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] > nums[j])
                    c++;
            }
            count.push_back(c);
        }

        return count;
    }
};

// solution

class Solution
{
public:
    void merge(vector<int> &count, vector<pair<int, int>> &v, int left, int mid, int right)
    {
        vector<pair<int, int>> temp(right - left + 1);
        int j = mid + 1;
        int i = left;
        int k = 0;

        while (i <= mid && j <= right)
        {
            if (v[i].first <= v[j].first)
            {
                temp[k++] = v[j++];
            }
            else
            {
                count[v[i].second] += right - j + 1;
                temp[k++] = v[i++];
            }
        }

        while (i <= mid)
        {
            temp[k++] = v[i++];
        }

        while (j <= right)
        {
            temp[k++] = v[j++];
        }

        for (int i = left; i <= right; i++)
        {
            v[i] = temp[i - left];
        }
    }

    void mergeSort(vector<int> &count, vector<pair<int, int>> &v, int left, int right)
    {
        if (left < right)
        {
            int mid = left + (right - left) / 2;
            mergeSort(count, v, left, mid);
            mergeSort(count, v, mid + 1, right);
            merge(count, v, left, mid, right);
        }
    }

    vector<int> countSmaller(vector<int> &nums)
    {

        int n = nums.size();
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++)
        {
            pair<int, int> p;

            p.first = nums[i];
            p.second = i;
            v[i] = p;
        }
        vector<int> count(n, 0);
        mergeSort(count, v, 0, n - 1);
        return count;
    }
};