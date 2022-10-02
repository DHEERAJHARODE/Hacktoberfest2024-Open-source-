#include<iostream>
using namespace std;

void TOH(int n, int left, int mid, int right)
{
    if(n==1)
    {
        cout<<left<<" "<<right<<endl;
        return;
    }
    TOH(n-1,left,right,mid);
        cout<<left<<" "<<right<<endl;
    TOH(n-1,mid,left,right);
}

int main()
{
    int n;
    cin >> n;
    cout<<(1<<n)-1<<endl;
    TOH(n,1,2,3);
}