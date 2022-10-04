//  Kashish Ahuja
//  Program to display Floyd's Triangle

#include<iostream>
using namespace std;

int main()
{
    cout<<"Enter number of rows: ";
    int n;
    cin>>n;
    int count=1;
    for(int i=0; i<n; i++)
    {   
        for(int j=0; j<i+1; j++)
        {
            cout<<count<<" ";
            count++;
        }
        cout<<"\n";
    }
    return 0;
}