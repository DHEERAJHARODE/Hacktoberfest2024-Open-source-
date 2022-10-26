// next_permutation()
// it will return a boolean value if the next_permutation is possible then it will 
// replace the original string with the next permutation string and return true or else false
#include<bits/stdc++.h>
using namespace std;

// to print next permutations
void perm(string s){
    cout << "Next Permutations" << endl;
    do{
        cout << "-> " << s << endl;
    }while(next_permutation(s.begin(),s.end()));
}

// to print previous permutations
void prev_perm(string s){
    cout << endl << "Prev Permutations" << endl;
    do{
        cout << "-> " << s << endl;
    }while(prev_permutation(s.begin(),s.end()));
}

// sort on strings will sort them in lexicographic order
void lex_sort(string s){
    sort(s.begin(), s.end());
    cout << endl << "Sorted lexicographically: \n-> " << s << endl << endl;
}

int main(){
    string s;
    cout<< endl << "Enter String: "; 
    cin >> s;
    perm(s);
    prev_perm(s);
    lex_sort(s);
}