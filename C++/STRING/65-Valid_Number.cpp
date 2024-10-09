#include<bits/stdc++.h>
using namespace std;
bool isNumber(string &s) {
    return is_valid_number(s);
}

bool is_valid_number(string& s) {
    if (s.empty()) return false;

    size_t i = 0;
    if (s[i] == '+' || s[i] == '-') i++;

    bool has_integer_part = false;
    while (i < s.size() && isdigit(s[i])) {
        has_integer_part = true;
        i++;
    }

    bool has_decimal_part = false;
    if (i < s.size() && s[i] == '.') {
        i++;
        while (i < s.size() && isdigit(s[i])) {
            has_decimal_part = true;
            i++;
        }
    }

    if (i < s.size() && (s[i] == 'e' || s[i] == 'E')) {
        i++;

        if (i < s.size() && (s[i] == '+' || s[i] == '-')) i++;

        if (i == s.size() || !isdigit(s[i])) {
            return false;
        }
        while (i < s.size() && isdigit(s[i])) {
            i++;
        }
    }
    return i == s.size() && (has_integer_part || has_decimal_part);
}


int main() {
    string s1 = "0";
    cout << isNumber(s1) << endl;
    return 0;
}