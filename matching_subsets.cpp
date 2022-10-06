class Solution {
public:
    int numMatchingSubseq(string str, vector<string>& words) {
        int n = words.size();
      map <char, vector <string> > m;
      for(int i=0;i<words.size();i++){
         m[words[i][0]].push_back(words[i]);
      }
      int res = 0;
      for(int i=0;i<str.size();i++){
         char ch = str[i];
         if(m.find(ch) != m.end()){
            vector <string> temp = m[ch];
            m.erase(ch);
            for(int j=0;j<temp.size();j++){
               if(temp[j].size() == 1){
                  res++;
               } else {
                  m[temp[j][1]].push_back(temp[j].substr(1));
               }
            }
         }
      }
      return res;
    }
};
