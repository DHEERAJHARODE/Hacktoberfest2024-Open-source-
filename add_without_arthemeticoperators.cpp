#include <bits/stdc++.h>
using namespace std;

int Add(int x, int y)
{
	if (y == 0)
		return x;
	else
		return Add( x ^ y,(unsigned) (x & y) << 1);
}
int main()
{
    int a,b;
    cin>>a>>b;
    cout << Add(a, b);
    return 0;
}
//contributed by ayush jha
