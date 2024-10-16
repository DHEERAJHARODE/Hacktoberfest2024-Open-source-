#include <bits/stdc++.h>
// #include<utility>
using namespace std;

void pair_Show()
{
    pair<int, int> p = {1, 3};
    cout << p.first << p.second << endl; // 1 3

    pair<int, pair<int, int>> a = {2, {1, 3}};
    cout << a.first << a.second.second << a.second.first << endl;   // 2 3 1

    pair<int, int> arr[] = {{2, 3}, {1, 5}, {6, 7}};
    cout << arr[1].second << endl;  // 5
}

int main()
{
    pair_Show();
    return 0;
}