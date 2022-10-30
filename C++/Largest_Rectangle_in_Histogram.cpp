class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int maxarea = 0;
        vector<int> left = nsl(heights);  // Nearest smallest element in left
        vector<int> right = nsr(heights); // Nearest smallest element in right
        for (int i = 0; i < heights.size(); i++)
        {
            if (right[i] == -1) // to handle the case in which all are -1 i.e. [2,2,2,2]
                right[i] = heights.size();
            maxarea = max(maxarea, (right[i] - left[i] - 1) * heights[i]);
        }
        return maxarea;
    }

private:
    vector<int> nsl(vector<int> h)
    {
        int n = h.size();
        stack<int> s;
        vector<int> v(n, 0);
        for (int i = 0; i < n; i++)
        {
            while (!s.empty() and h[s.top()] >= h[i])
            {
                s.pop();
            }
            if (s.empty())
                v[i] = -1;
            else
                v[i] = s.top();
            s.push(i);
        }
        return v;
    }
    vector<int> nsr(vector<int> h)
    {
        int n = h.size();
        stack<int> s;
        vector<int> v(n, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            while (!s.empty() and h[s.top()] >= h[i])
            {
                s.pop();
            }
            if (s.empty())
                v[i] = -1;
            else
                v[i] = s.top();
            s.push(i);
        }
        return v;
    }
};