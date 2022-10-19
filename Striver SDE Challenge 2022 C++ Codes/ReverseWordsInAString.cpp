string reverseWords(string str) {
        int i = 0, n = str.length();
        string word="",ans="";
        //Iterate the string and keep on adding to form a word
        //If empty space is encountered then add the current word to the result
        while(i < n) {
            if(str[i] != ' ')
                word += str[i];
            else if(str[i] == ' ' && word!="") {
                if (ans!="") ans = word + " " + ans;
                else ans = word;
                word = "";
            }
            i++;
        }
        //till here, last n-1 words are added as there is no space after last word
        //Last word is added
        if (word!="") {
            if (ans!="") ans = word + " " + ans;
            else ans = word;
        }
        return ans;
    }