#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    char str1[20], str2[20];
    int len1, len2, i, j, found=0, not_found=0;
    cout<<"Enter the First String: ";
    cin>>str1;
    cout<<"Enter the Second String: ";
    cin>>str2;
    len1 = strlen(str1);
    len2 = strlen(str2);
    if(len1 == len2)
    {
        for(i=0; i<len1; i++)
        {
            found = 0;
            for(j=0; j<len1; j++)
            {
                if(str1[i] == str2[j])
                {
                    found = 1;
                    break;
                }
            }
            if(found == 0)
            {
                not_found = 1;
                break;
            }
        }
        if(not_found == 1)
            cout<<"\nStrings are not Anagram";
        else
            cout<<"\nStrings are Anagram";
    }
    else
        cout<<"\nCharacter count Mismatched!";
    cout<<endl;
    return 0;
}