#include <iostream>
using namespace std;
bool isVowel(char ch)
{
    ch = toupper(ch);
    return (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
}
int countVowels(string s)
{
    int count = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (isVowel(s[i])) // check vowel or not
            ++count;
    }
    return count;
}

int main()
{
    string s = "shree";
    cout << countVowels(s);
    return 0;
}