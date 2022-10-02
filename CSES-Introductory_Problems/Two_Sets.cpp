#include <iostream>
#include <vector>
using namespace std;
int main()
{
    long long int n;
    cin >> n;
    long long int sum = n * (n + 1) / 2;
    if (sum & 1)
        cout << "NO";
    else
    {
        cout << "YES" << endl;
        vector<long long int> arr1, arr2;
        sum = sum / 2ll;
        while (n)
        {
            if (sum - n >= 0)
            {
                arr1.push_back(n);
                sum -= n;
            }
            else
                arr2.push_back(n);
            n--;
        }
        cout << arr1.size() << endl;
        for (long long int x : arr1)
            cout << x << " ";
        cout << endl;
        cout << arr2.size() << endl;
        for (long long int x : arr2)
            cout << x << " ";
    }
    return 0;
}