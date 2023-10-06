#include<bits/stdc++.h>
using namespace std;

int sum(vector<int>& arr) {
    int ans=0;
    for(auto element:arr) ans+=element;
    return ans;
}
int main() {
    int n; // the size of the array
    cout<<"Enter the size of the array: ";
    cin>>n;
    cout<<"Enter array elements seperated by space: \n";
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    //printing the sum of all array elements.
    cout<<sum(arr)<<endl;
}