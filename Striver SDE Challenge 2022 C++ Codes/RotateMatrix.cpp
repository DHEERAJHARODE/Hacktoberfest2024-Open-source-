//different question on CodeStudio even thogh same solution given by Striver

class Solution {
public:
    void swap(vector<vector<int>>& nums, int i, int j, int a, int b){
        int temp=nums[i][j];
        nums[i][j]=nums[a][b];
        nums[a][b]=temp;
    }
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n/2;j++)
                swap(matrix, i, j, i, n-1-j);
                // swap(matrix, matrix[i][j], matrix[i][n-1-j]);
        }//i
        int k=n-1,l=n-1;
        for(int i=0;i<n-1;i++){
            for(int j=0;j<k;j++)
                swap(matrix, i, j, l--, k);
                // swap(matrix, matrix[i][j], matrix[l--][k]);
            l=n-1,k--;
        }
    }
};