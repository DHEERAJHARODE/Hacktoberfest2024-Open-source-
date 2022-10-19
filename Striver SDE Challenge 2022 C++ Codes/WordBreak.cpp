void wb(int ind, string tmp, string s, vector<string>& ans, vector<string>& dict){
        if(ind==s.size()){
            ans.push_back(tmp.substr(0,tmp.size()-1));
            return;
        }
        for(int i=ind;i<s.size();i++){
            if(find(dict.begin(),dict.end(),s.substr(ind,i-ind+1)) != dict.end())
                wb(i+1,tmp+s.substr(ind,i-ind+1)+" ",s,ans,dict);
        }
    }
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        vector<string> ans;
        wb(0,"",s,ans,dict);
        return ans;
    }

//check array
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> check(s.size()+1,false);
        check[0]=true;
        for(int i=1;i<=s.size();i++){
            for(int j=0;j<i;j++){
                if(check[j] and find(wordDict.begin(), wordDict.end(), s.substr(j,i-j)) != wordDict.end()){
                    check[i]=true;
                    break;//next i
                }
            }
        }
        return check[s.size()];
    }
};

//substr(index,length)