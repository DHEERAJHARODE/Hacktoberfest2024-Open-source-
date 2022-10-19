#include<bits/stdc++.h>
bool isPossible(long long barrier, int n, vector<int> &time){
    long long sum=0;
    for(int i=0;i<time.size();i++){
        if(sum+time[i]<=barrier)
            sum=sum+time[i]; 
        else{
            sum=time[i];
            n--;
            if(time[i]>barrier) return false;
        }
    }
    if(n>0) return true;
    return false;
}

long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{
    long long beg=*min_element(time.begin(),time.end());
    long long end=accumulate(time.begin(),time.end(),0);
    //now our range is set to min and max ans possible. We use bins to find our ans
    while(beg<=end){
        long long mid=(beg+end)/2;
        if(isPossible(mid,n,time))
            end=mid-1; //check of lower ans
        else beg=mid+1;//this barrier is lower, increase it
    }
    return beg;
}

//alternative code
#include<bits/stdc++.h>
bool isPossible(vector<int>& arr, int mid, int m){
    int stu= 1, sum=0;
    for(int pgs: arr){
        sum += pgs;
        if(sum > mid){
            sum=pgs;
            stu++;
        }
    }
    return stu<=m;
}
int allocateBooks(vector<int> arr, int n, int m) {
    int mini = *max_element(begin(arr), end(arr));
    int maxi = accumulate(begin(arr), end(arr), 0);
    int ans=0;
    while(mini <= maxi){
        //mid stores max pgs per student for this trial
        int mid = (maxi+mini)/2;
        if(isPossible(arr,mid,m)){
            ans=mid;
            maxi=mid-1;
        }
        else mini=mid+1;
    }
    return ans;
}