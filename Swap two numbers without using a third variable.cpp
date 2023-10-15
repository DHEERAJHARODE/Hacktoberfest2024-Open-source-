#include<iostream>

using namespace std;

void swap(int , int );

void swap ( int a, int b)
{
    a = a + b;
    b = a - b;
    a = a - b;
    printf("\nAfter swapping: x = %d and y = %d\n", a, b); 
}


int main()
{
    int x,y;
    cout<<"Enter number x:"<<endl;
    cin>>x;
    cout<<"Enter number y:"<<endl;
    cin>>y;
    printf("\nBefore swapping: x = %d and y = %d\n", a, b); 
    swap(x,y);
    return 0;
}

