#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    char arr[n + 1];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    bool flag = true;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != arr[n - 1 - i])
        {
            flag = false;

            break;
        }
    }
    if (flag == true)
    {
        cout << "pallindrome" << endl;
    }
    else
    {
        cout << "not pallindrome" << endl;
    }

    return (0);
}