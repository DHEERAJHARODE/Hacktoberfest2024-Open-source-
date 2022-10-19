#include <bits/stdc++.h>

vector<int> ninjaAndSortedArrays(vector<int>& nums1, vector<int>& nums2, int m, int n) {
    int k = m+n-1;
    int i=m-1, j=n-1; //indices of last elems of nums1 and 2
    while(i>=0 && j>=0){
        if(nums1[i]>nums2[j])
            nums1[k--]=nums1[i--];
        else
            nums1[k--]=nums2[j--];
    }
    while(i>=0)
        nums1[k--]=nums1[i--];
    while(j>=0)
        nums1[k--]=nums2[j--];
    return nums1;
}