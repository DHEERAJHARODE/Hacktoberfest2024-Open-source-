#include <bits/stdc++.h>
using namespace std;

long long findMinDiff(vector<long long> a, long long n, long long m){
    // code
    sort(a.begin(), a.end());
    int i = 0;
    int r = m - 1;
    int mini = INT_MAX;
    int ans = 0;
    while (r < n)
    {
        ans = a[r] - a[i];
        mini = min(mini, ans);
        i++;
        r++;
    }
    return mini;
}
int main(){
    long long N = 8, M = 5;
    vector<long long> A = {3, 4, 1, 9, 56, 7, 9, 12};
    cout<<findMinDiff(A, N, M)<<endl;
    return 0;
}