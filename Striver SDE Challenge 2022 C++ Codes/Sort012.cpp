#include <bits/stdc++.h> 
void swap(int *nums, int a, int b){
    int temp=nums[a];
    nums[a]=nums[b];
    nums[b]=temp;
}
void sort012(int *nums, int n)
{
    int i=0,j=0,k=n-1;
    while(j<=k){
        if(nums[j]==0){
            swap(nums,i++,j++);
        }
        else if(nums[j]==2)
            swap(nums,j,k--);
        else
            j++;
    }
}