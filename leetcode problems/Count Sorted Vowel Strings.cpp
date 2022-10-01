// brute force
class Solution {
public:
    vector<char> v{'a','e','i','o','u'};
    int countVowelStrings(int n) {
        int ans =0;
        
        for(auto c: v)
        {
            ans += count(n-1, c);
        }
        return ans;
    }
    
    int count(int len, char last_char)
    {
        if(len == 0) return 1;
        
        int temp = 0;
        
        for(auto c: v)
        {
            if(last_char >= c)
            {
                temp+= count(len-1, c);
            }
        }
        return temp;
    }
};

// optimized approach

class Solution {
public:
    int countVowelStrings(int n) {
        int a = 1;
        int e = 1;
        int i = 1;
        int o = 1;
        int u = 1;
        
        while (--n){
            e += a;
            i += e;
            o += i;
            u += o;         
        }
        return a + e + i + o + u;
    }
};

// mathematical approach
class Solution {
    
public:
    int countVowelStrings(int n) {
        
        return (n+4)*(n+3)*(n+2)*(n+1) / 24;
    }
};