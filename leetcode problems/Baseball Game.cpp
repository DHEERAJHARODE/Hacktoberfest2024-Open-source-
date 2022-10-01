class Solution
{
public:
    int calPoints(vector<string> &ops)
    {

        stack<int> s;
        int ans = 0, value1, value2;

        for (string i : ops)
        {
            if (i == "C")
            {
                s.pop();
            }
            else if (i == "D")
            {
                s.push(s.top() * 2);
            }
            else if (i == "+")
            {
                value1 = s.top();
                s.pop();
                value2 = s.top();
                s.push(value1);
                s.push(value1 + value2);
            }
            else
            {
                s.push(stoi(i));
            }
        }
        while (!s.empty())
        {
            ans += s.top();
            s.pop();
        }

        return ans;
    }
};
