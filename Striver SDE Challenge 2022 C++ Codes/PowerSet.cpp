//BIT MANIP
vector<string> AllPossibleStrings(string s){
		    int n=s.size();
		    string st;
		    vector<string> ans;
		    for(int i=0;i<1<<n;i++){
		        st="";
		        for(int j=0;j<n;j++){
		            if(i & (1<<j)) st+=s[j];
		        }
		        if (st.length() > 0) ans.push_back(st);
		    }
		    sort(ans.begin(), ans.end());
		    return ans;
		}

//Recursive
vector<vector<int>> subsets(vector<int>& v) {
        vector<vector<int>> ans;
        f(0,v,ans,{});
        return ans;
    }
    void f(int ind, vector<int>& v, vector<vector<int>>& ans, vector<int> temp){
        if(ind==v.size()) {
            ans.push_back(temp);
            return;
        }
        //take
        temp.push_back(v[ind]);
        ans.push_back(temp);
        f(ind+1,v,ans,temp);
        //dont take
        temp.pop_back();
        ans.pop_back();
        f(ind+1,v,ans,temp);
    }