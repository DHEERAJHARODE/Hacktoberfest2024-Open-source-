#include<bits/stdc++.h>
using namespace std;

vector<int> nums;
int to_find;
void bin_search(int low, int high)
{
    int mid = (low + high)/2;
    if(nums[mid] == to_find ) 
    {
        cout<<mid;
    }
    else if(to_find > nums[mid]) bin_search(mid+1,high);
    else bin_search(low, mid-1);

}

int main()
{
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin>>ele;
        nums.push_back(ele);
    }
    
    cin>> to_find;
    
    bin_search(0,n);
    return 0;
}