#include <bits/stdc++.h>
#include <string.h>
using namespace std;

class Solution {

    bool isValidPart(string part) {
        bool isValid = true;

        // cheacking all chars are integers only
        for(int i=0; i<part.size(); i++) {
            if(part[i]<'0' or part[i] > '9')
                isValid = false;
            if(!isValid)
                return false;
        }

        // checking not have any leading zeros
        for(int i=0; i<part.size(); i++) {
            if(part[i] == '0')
                return false;
            else
                break;
        }

        // checking range 0 to 255
        int val = stoi(part); // covert in int
        if(val > 255)
            isValid = false;

        return isValid;

    }

public:
    int isValid(string s) {
        // your code here
        int counter = 0;
        // count number of '.'
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '.') counter++;
        }
        if (counter != 3) return 0;

        // stores the valid numbers
        vector<string> singlePart; // for storing parts of whole ip address using delimiter as a '.'
        string part = ""; // for storing part till '.' while we iterating one by one char

        for(int i=0; i<s.size(); i++) {
            if(s[i] == '.'){
                singlePart.push_back(part); // when we reach at '0' we store before part in parts vecor to compare later
                part = ""; // and clear part string again
            } else {
                part += s[i]; // we are storing every char and building part till we reach '.'
            }
        }
        singlePart.push_back(part); // here we push back last part which left after reaching last '.'

        
        // Let's check singlePart are 4 or not after splitting them
        if(singlePart.size() != 4)
            return 0;

        int result = 1;
        for(string part: singlePart) {
            if(!isValidPart(part))
                result = 0;
        }

        return result;
    }

};


int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isValid(s) << endl;
    }
    return 0;
}
