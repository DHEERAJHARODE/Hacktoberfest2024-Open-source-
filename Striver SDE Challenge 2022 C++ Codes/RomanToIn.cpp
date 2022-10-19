int romanToInt(string s) {
        map<char,int>romans;
        romans={
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };
        int ans=romans[s[0]];
        for(int i=1;i<s.size();i++){
            int prev=romans[s[i-1]];
            int cur=romans[s[i]];
            if(cur<=prev) ans+=cur;
            else ans=ans-prev+(cur-prev);
        }
        return ans;
    }