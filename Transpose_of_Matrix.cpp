cout << "Enter rows and columns of matrix: ";
   cin >> row >> column;

   cout << "\nEnter elements of matrix: " << endl;

   // Storing matrix elements
   for (int i = 0; i < row; ++i) {
      for (int j = 0; j < column; ++j) {
         cout << "Enter element a" << i + 1 << j + 1 << ": ";
         cin >> a[i][j];
      }
   }

   // Printing the a matrix
   cout << "\nEntered Matrix: " << endl;
   for (int i = 0; i < row; ++i) {
      for (int j = 0; j < column; ++j) {
         cout << " " << a[i][j];
         if (j == column - 1)
            cout << endl << endl;
      }
   }

   // Computing transpose of the matrix
   for (int i = 0; i < row; ++i)
      for (int j = 0; j < column; ++j) {
         transpose[j][i] = a[i][j];
      }

   // Printing the transpose
   cout << "\nTranspose of Matrix: " << endl;
   for (int i = 0; i < column; ++i)
      for (int j = 0; j < row; ++j) {
         cout << " " << transpose[i][j];
         if (j == row - 1)
            cout << endl << endl;
      }

   return 0;
}
