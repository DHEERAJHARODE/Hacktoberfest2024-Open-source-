// C++ implementation to find largest area rectangular
// submatrix with equal number of 1's and 0's
#include <bits/stdc++.h>
  
using namespace std;
  
#define MAX_ROW 10
#define MAX_COL 10
  
// This function basically finds largest 0
// sum subarray in arr[0..n-1]. If 0 sum
// does't exist, then it returns false. Else
// it returns true and sets starting and
// ending indexes as start and end.
bool subArrWithSumZero(int arr[], int &start, 
                              int &end, int n)
{
    // to store cumulative sum
    int sum[n];
      
    // Initialize all elements of sum[] to 0
    memset(sum, 0, sizeof(sum));
      
    // map to store the indexes of sum
    unordered_map<int, int> um;
      
    // build up the cumulative sum[] array
    sum[0] = arr[0];
    for (int i=1; i<n; i++)
        sum[i] = sum[i-1] + arr[i];
      
    // to store the maximum length subarray
    // with sum equal to 0
    int maxLen = 0;
      
    // traverse to the sum[] array
    for (int i=0; i<n; i++)    
    {
        // if true, then there is a subarray
        // with sum equal to 0 from the
        // beginning up to index 'i'
        if (sum[i] == 0)
        {
            // update the required variables
            start = 0; 
            end = i;
            maxLen = (i+1);
        }
          
        // else if true, then sum[i] has not 
        // seen before in 'um'
        else if (um.find(sum[i]) == um.end())
            um[sum[i]] = i;
          
        // sum[i] has been seen before in the
        // unordered_map 'um'    
        else
        {
            // if previous subarray length is smaller
            // than the current subarray length, then
            // update the required variables
            if (maxLen < (i-um[sum[i]]))
            {
                maxLen = (i-um[sum[i]]);
                start = um[sum[i]] + 1;
                end = i;
            }
        }    
    }    
      
    // if true, then there is no
    // subarray with sum equal to 0
    if (maxLen == 0)
        return false;
          
    // else return true    
    return true;    
}
  
// function to find largest area rectangular
// submatrix with equal number of 1's and 0's
void maxAreaRectWithSumZero(int mat[MAX_ROW][MAX_COL], 
                                    int row, int col)
{
    // to store intermediate values
    int temp[row], startRow, endRow;
      
    // to store the final outputs
    int finalLeft, finalRight, finalTop, finalBottom;
    finalLeft = finalRight = finalTop = finalBottom = -1;
    int maxArea = 0;
      
    // Set the left column    
    for (int left = 0; left < col; left++)
    {
        // Initialize all elements of temp as 0
        memset(temp, 0, sizeof(temp));
          
        // Set the right column for the left column
        // set by outer loop
        for (int right = left; right < col; right++)
        {
            // Calculate sum between current left
            // and right for every row 'i'
            // consider value '1' as '1' and
            // value '0' as '-1'
            for (int i=0; i<row; i++)
                temp[i] += mat[i][right] ? 1 : -1;
                  
            // Find largest subarray with 0 sum in
            // temp[]. The subArrWithSumZero() function 
            // also sets values of finalTop, finalBottom,
            // finalLeft and finalRight if there exists
            // a subarray with sum 0 in temp
            if (subArrWithSumZero(temp, startRow, endRow, row))
            {
                int area = (right - left + 1) * 
                                       (endRow - startRow + 1);
  
                // Compare current 'area' with previous area
                // and accodingly update final values
                if (maxArea < area)
                {
                    finalTop = startRow;
                    finalBottom = endRow;
                    finalLeft = left;
                    finalRight = right;                    
                    maxArea = area;
                }
            }
        }
    }
      
    // if true then there is no rectangular submatrix
    // with equal number of 1's and 0's
    if (maxArea == 0)
        cout << "No such rectangular submatrix exists:";
      
    // displaying the top left and bottom right boundaries
    // with the area of the rectangular submatrix    
    else
    {
        cout << "(Top, Left): " 
             << "(" << finalTop << ", " << finalLeft
             << ")" << endl; 
               
        cout << "(Bottom, Right): " 
             << "(" << finalBottom << ", " << finalRight 
             << ")" << endl;      
          
        cout << "Area: " << maxArea << " sq.units";     
    }
}
  
// Driver program to test above
int main()
{
    int mat[MAX_ROW][MAX_COL] = { {0, 0, 1, 1},
                                    {0, 1, 1, 0},
                                    {1, 1, 1, 0},
                                  {1, 0, 0, 1} };    
    int row = 4, col = 4;
    maxAreaRectWithSumZero(mat, row, col);
    return 0;                      
                        
} 
