//  Input number of rows (half of the diamond): 5                         
                                                                       
//     *                                                                  
//    ***                                                                 
//   *****                                                                
//  *******                                                               
// *********                                                              
//  *******                                                               
//   *****                                                                
//    ***                                                                 
//     *

#include <bits/stdc++.h>
using namespace std;


void Diamond(int n)
{
	int space = n - 1;

	// run loop 
	
	for (int i = 0; i < n; i++)
	{
		// loop for initially space,
	
		for (int j = 0;j < space; j++)
			cout << " ";

		// Print i+1 stars
		for (int j = 0; j <= i; j++)
			cout << "* ";

		cout << endl;
		space--;
	}

	space = 0;

	// run loop
	for (int i = n; i > 0; i--)
	{
		// loop for initially space,

		for (int j = 0; j < space; j++)
			cout << " ";

		// Print i stars
		for (int j = 0;j < i;j++)
			cout << "* ";

		cout << endl;
		space++;
	}
}

int main()
{
    int num;
    cout<<"Enter a number here : ";
    cin>>num;
	Diamond(num);
	return 0;
}
