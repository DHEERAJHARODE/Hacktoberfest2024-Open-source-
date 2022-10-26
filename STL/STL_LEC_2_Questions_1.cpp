// given N elements, print the elements that occurs maximum no . of times
// input
// 5
// 1 3 3 3 2

// output
// 3

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, max=1;
    map<int,int> mpp;
    cin >> n;
    while(--n){
        int x;
        cin >> x;
        mpp[x]++;
        if(mpp[x] > mpp[max]){
            max = x;
        }
    }
    cout << "The Number with highest frequency is: " << mpp[max];
}