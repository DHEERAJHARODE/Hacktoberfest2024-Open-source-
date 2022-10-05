// Github username: Smit-Vasoya-Tridhya
// Aim: defination of the problem is given below
    // Given an array of integers and a target value, determine the number of pairs of array elements that have a difference equal to the target value.
    //  This Program is used for the finding the Pair of the elements in the array  using dynamic programming approch in c++
    //  and i have used Vector for the dynamic programming.
    // this problem is also available in the hacker rank and i have solved it in first try (https://www.hackerrank.com/challenges/pairs/problem?isFullScreen=true)
// Date: 5th octomber 2022
// GitHub : https://github.com/Smit-Vasoya-Tridhya

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

int pairs(int k, vector<int> arr) {
    int cnt=0;
    sort(arr.begin(),arr.end());
    unordered_set<int> s;
    
    for(int i=0;i<=arr.size();i++){
        int j= arr[i]-k;
        if(s.find(j)!=s.end()){
            cnt++;
        }
        s.insert(arr[i]);
    }
    
    return cnt;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = pairs(k, arr);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
