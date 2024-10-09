#include<bits/stdc++.h>
using namespace std;

vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> result;
    for(int i = 0, j; i < words.size(); i = j) {
        int width = 0;
        for(j = i; j < words.size() && width + words[j].size() + j - i <= maxWidth; j++) {
            width += words[j].size();
        }
        int space = 1, extra = 0;
        if(j - i != 1 && j != words.size()) {
            space = (maxWidth - width) / (j - i - 1);
            extra = (maxWidth - width) % (j - i - 1);
        }
        string line = words[i];
        for(int k = i + 1; k < j; k++) {
            line += string(space, ' ');
            if(extra > 0) {
                extra--;
                line += " ";
            }
            line += words[k];
        }
            
        line += string(maxWidth - line.size(), ' ');
        result.push_back(line);
    }
    return result;
}

int main() {
    vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
    int maxWidth = 16;
    vector<string> result = fullJustify(words, maxWidth);
    for(auto &s : result) {
        cout << s << endl;
    }
    return 0;
}