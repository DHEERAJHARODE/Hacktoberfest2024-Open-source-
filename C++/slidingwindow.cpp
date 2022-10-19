#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n;i++) 
    {
        cin >> a[i];
    }
    int k;
    cin >> k;
    int window_sum=0, max_sum=0, curr_sum=0;
    for (int i = 0; i < k;i++)
    {
        max_sum += a[i];
    }
    window_sum = max_sum;
    for (int i = k; i < n;i++)
    {
        window_sum = window_sum + a[i] - a[i - k];
        max_sum=max(max_sum, window_sum);
    }
    cout << max_sum << endl;
    return 0;
}
