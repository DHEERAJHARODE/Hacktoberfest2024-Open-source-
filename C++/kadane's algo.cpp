 #include<iostream>
 using namespace std;
 int k(int a[],int n){
    int highestmax =0;
    int current =0;
    for(int i=0;i<n;i++){
        current = max(a[i],current+a[i]);
        highestmax = max(highestmax,current);
    }
    return highestmax;
 } 
 int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"The maximum sum is: "<<k(a,n)<<endl;
    return 0;

    }