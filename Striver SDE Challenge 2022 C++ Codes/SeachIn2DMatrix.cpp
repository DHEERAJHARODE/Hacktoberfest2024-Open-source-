#include <bits/stdc++.h> 
#include <vector>

bool findTargetInMatrix(vector < vector < int >> & matrix, int m, int n, int target) {
    int beg=0;
    int end=m*n-1;
    while(beg<=end){
        int mid=beg+(end-beg)/2;
        if(target==matrix[mid/n][mid%n])
            return true;
        else if(target > matrix[mid/n][mid%n])
            beg=mid+1;
        else
            end=mid-1;
    }
    return false;
}