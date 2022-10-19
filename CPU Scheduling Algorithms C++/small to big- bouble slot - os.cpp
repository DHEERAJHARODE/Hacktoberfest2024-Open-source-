
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Number of Prosoccer : ";
    cin>>n;
    int CPUT[n],WT[n]={0},TT[n],AT[n];
    float avgW=0,sumW=0,avgT=0,sumT=0;
    for(int i=0;i<n;i++)
    {
        cout<<"CPU Time of P"<<i+1<<": ";
        cin>>CPUT[i];

        cout<<"AT Time of P"<<i+1<<": ";
        cin>>AT[i];
    }
//
        for (int step = 0; step < n; ++step) {

            // loop to compare array elements
            for (int i = 0; i < n - step; ++i) {

            // compare two adjacent elements
            // change > to < to sort in descending order
            if (CPUT[i] >CPUT[i + 1]) {

                // swapping elements if elements
                // are not in the intended order
                int temp = CPUT[i];
                CPUT[i] = CPUT[i + 1];
                CPUT[i + 1] = temp;
            }
            }
        }
//
    for(int i=1;i<n;i++)
    {
        WT[i]=CPUT[i-1]+WT[i-1];
    }

    for(int i=0;i<n;i++)
    {
        WT[i]-=AT[i];
    }

    for(int i=0;i<n;i++)
    {
        TT[i]=CPUT[i]+WT[i];
    }


    cout<<"P     CPU    WT   TT"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<i+1<<"    "<<CPUT[i]<<"    "<<WT[i]<<"     "<<TT[i]<<endl;
    }

    for(int i=0;i<n;i++)
    {
        sumW+=WT[i];
        sumT+=TT[i];
    }

    avgT=sumT/n;
    avgW=sumW/n;

    cout<<"WT Avg : "<<avgW<<endl;
    cout<<"TT Avg : "<<avgT<<endl;

    cout<<"\n\n|";
    for(int i=0;i<n;i++)
    {
        cout<<"P |"<<i+1;
    }

    cout<<"\n0";
     for(int i=0;i<n;i++)
    {
        cout<<" "<<TT[i];
    }

    return 0;
}
