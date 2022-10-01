#include<iostream>
using namespace std;
void isPowerOfTwo(int x){
    if((x&(x-1)) == 0){
        cout<<x<<" is a power of 2\n";
    }
    else{
        cout<<x<<" is not a power of 2\n";
    }
    return;
}
int main(){
    cout<<"Enter any number :\n";
    int n;
    cin>>n;
    isPowerOfTwo(n);
    return 0;
}