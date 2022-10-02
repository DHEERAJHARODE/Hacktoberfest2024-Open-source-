#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    long long int arr[n], sum = 0, diff = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    for (int i = 0; i < (1 << n); i++)
    {
        long long int curr = 0;
        for (int j = 0; j < n; j++)
            if ((1 << j) & i)
                curr += arr[j];
        diff = min(diff, abs(sum - curr - curr));
    }
    cout << diff << endl;
    return 0;
}
