class Solution
{
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        vector<string> vec;
        //declare an unordered_map whose key will be a string and value will be quantity of that string
        unordered_map<string, int> m;
        for (int i = 0; s[i + 9] != '\0'; i++)
        {
            string str = "";
            //making string of 10 elements
            for (int a = 0, b = i; a < 10; a++, b++)
            {
                str += s[b];
            }
            //check if that string already present in unordered_map or not
            //if string is not present then push it
            //if it is present then increase its quantity
            auto itr = m.find(str);
            if (itr == m.end())
            {
                m.emplace(str, 1);
            }
            else
            {
                itr->second++;
            }
        }
        //iterate over the unurdered_map and check those elements whose quantity is above one
        for (auto x : m)
        {
            if (x.second > 1)
            {
                vec.push_back(x.first);
            }
        }
        return vec;
    }
};
