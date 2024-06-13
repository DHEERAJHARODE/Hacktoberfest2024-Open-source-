#include<bits/stdc++.h>
using namespace std;

int main()
{
    int array[5]={9,6,5,1,12};

    sort(array,array+5);    //Sort in ascending order
    cout<<"Array in ascending order: "<<endl;
    for(int i=0;i<5;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;

    sort(array,array+5,greater<int>());    //Sort in descending order
    cout<<"Array descending order: "<<endl;
    for(int i=0;i<5;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;

    return 0;
}