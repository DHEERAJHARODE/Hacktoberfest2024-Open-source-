string longestCommonPrefix(vector<string>& strs) {
        //find min len string and that string
        if(strs.size()==1) return strs[0];
        int minl=INT_MAX,c=0;
        string mins;
        for(int i=0;i<strs.size();i++){
            int l=strs[i].size();
            if(l<minl){
                minl=l;
                mins=strs[i];
            }
        }
        for(int i=0;i<minl;i++){
            for(int j=0;j<strs.size();j++){
                if(strs[j][i]!=mins[i])//string j ka ith char
                    return mins.substr(0,c);
            }
            c++;
        }
        return mins.substr(0,c);
    }