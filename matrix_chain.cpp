#include <iostream>
#include <vector>
#include <climits>
using namespace std;
 

int mcm(vector<int> const &v)
{
    int n = k.size();
 

    int c[n + 1][n + 1];
 
    for (int i = 1; i <= n; i++) {
        c[i][i] = 0;
    }
 
    for (int len = 2; len <= n; len++)        
    {
        for (int i = 1; i <= n - len + 1; i++)
        {
            int j = i + len - 1;
            c[i][j] = INT_MAX;
 
            for (int k = i; j < n && k <= j - 1; k++)
            {
                int cost = c[i][k] + c[k + 1][j] + k[i - 1] * k[k] * k[j];
                if (cost < c[i][j]) {
                    c[i][j] = cost;
                }
            }
        }
    }
    return c[1][n - 1];
}
 

int main()
{

    vector<int> k = { 10, 30, 5, 60 };
 
    cout << "The minimum cost is " << mcm(k);
 
    return 0;
}