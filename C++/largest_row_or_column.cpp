// Printing the index and the sum of the maximum row or column for a 2D Array

#include <iostream>
#include<climits>
using namespace std;

void findLargest(int **input, int nRows, int mCols)
{
    int max=INT_MIN;  // declared the max to INT_MIN initially
    int i,j;
    int sumR,sumC;   // sumR= Sum of the elements of the Row , sumC=  Sum of the elements of the Column
    int max_row_index=0;  // Index of the maximum sum row
    int max_col_index=0;  // Index of the maximum sum column
    bool isRow=true;    // Assuming the sumR is maximum 
    bool isCol=false;   // Assuming the sumC is not maximum
    for(int i=0;i<nRows;i++)
    {
        sumR=0;
        for(int j=0;j<mCols;j++)
        {
            sumR=sumR+input[i][j];
        }
        if(sumR>max)
        {
            max=sumR;  // Initilising the max to sumR if sumR>max
            max_row_index=i;  // Updating the maximum row index
            isRow=true;  // Keeping the sumR as maximum only
        }
    }
    for(int j=0;j<mCols;j++)
    {
        sumC=0;
        for(int i=0;i<nRows;i++)
        {
            sumC=sumC+input[i][j];
        }
        if(sumC>max)
        {
            max=sumC;  // Initilising the max to sumC if sumC>max
            max_col_index=j;   // Updating the maximum column index
            isCol=true;   // Changing the sumC as maximum now
            isRow=false;   // And hence the sumR will now become minimum
        }
    }
    
    // Printing Accordingly
    if(isRow==true)
    {
        cout<<"row"<<" "<<max_row_index<<" "<<max;
    }
    else if(isCol==true)
    {
        cout<<"column"<<" "<<max_col_index<<" "<<max;
    }
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int row, col;
		cin >> row >> col;

		int **input = new int *[row];
		for (int i = 0; i < row; i++)
		{
			input[i] = new int[col];
			for (int j = 0; j < col; j++)
			{
				cin >> input[i][j];
			}
		}

		findLargest(input, row, col);
		cout << endl;
	}
}