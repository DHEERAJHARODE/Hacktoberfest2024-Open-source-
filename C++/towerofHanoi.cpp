#include<iostream>

using namespace std;
void solve_hanoi(int n, char &a, char &b, char &c)
{
    if(n == 1)
    {
        cout<<"Move from "<<a<<" to "<<c<<endl;
    }
    else
    {
        solve_hanoi(n-1, a, c, b);
        cout<<"Move from "<<a<<" to "<<c<<endl;
        solve_hanoi(n-1,b, a, c);
    }
}

int main()
{
    int n;
    cout<<"Enter the number of rings; ";
    cin>>n;
    char a='A';
    char b='B';
    char c='C';
    solve_hanoi(n,a,b,c);
    return 0;
}
