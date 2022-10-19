bool isPalindrome(string &s, int a, int b){
        while(a<b){
            if(s[a++]!=s[b--]) return false;
        }
        return true;
    }
    void pp(int ind, string &s, vector<string> &temp, vector<vector<string>> &ans){
        if(ind>=s.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=ind;i<s.size();i++){
            if(isPalindrome(s,ind,i)){
                temp.push_back(s.substr(ind,i-ind+1));
                pp(i+1,s,temp,ans);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        vector<vector<string>> ans;
        pp(0,s,temp,ans);
        return ans;
    }