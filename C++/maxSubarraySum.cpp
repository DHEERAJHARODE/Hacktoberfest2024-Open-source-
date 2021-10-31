#include <iostream>
using namespace std;

int maxSubarraySum(int arr[], int n){
    int maxSum= arr[0];
    int sum=0;

    for(int i=0; i<n; i++){
        sum+= arr[i];

        maxSum= max(sum, maxSum);

        if(sum<0)
            sum=0;
    }

    return maxSum;
}

int main(){
    int maxSum;
    int arr[] = { -2, -3, 4, -1, -2, 1, 6, -3 };
    int n = sizeof(arr)/sizeof(arr[0]);

    maxSum= maxSubarraySum(arr,n);

    cout<<maxSum;

return 0;
}
