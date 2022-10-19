bool isAnagram(string s, string t) {
        int sl=s.size(), st=t.size();
        if(sl!=st) return false;
        unordered_map<char,int> umap(26);
        for(int i=0;i<sl;i++){
            umap[s[i]]++;
        }
        for(int i=0;i<st;i++){
            umap[t[i]]--;
        }
        for(char i='a'; i<='z'; i++){
            if(umap[i]) return false;
        }
        return true;
    }