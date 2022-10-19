string countAndSay(int n) {
        if(n==1) return "1";
        string s=countAndSay(n-1);
        int c=0;
        string res="";
        for(int i=0;i<s.size();i++){
            c++;
            if(i==s.size()-1 or s[i]!=s[i+1]){
                res += to_string(c) + s[i];
                c=0;
            }
        }
        return res;
}