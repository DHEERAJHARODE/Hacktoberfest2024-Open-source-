class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int>lastind(26);
        vector<int>remove(26);
        for(int i=0;i<s.length();i++)
        {
            lastind[s[i]-'a']=i;
        }
        string stack = "";
        for(int i = 0; i < s.length(); ++i){
            while(stack.size()&& stack.back() > s[i] &&lastind[stack.back() - 'a'] > i && remove[s[i] - 'a'] == 0){
                 remove[stack.back() - 'a'] = 0;
                stack.pop_back();
            }
            if(remove[s[i] - 'a'] == 0) 
                stack.push_back(s[i]), remove[s[i] - 'a'] = 1;
        }
        return stack;
    }
};
