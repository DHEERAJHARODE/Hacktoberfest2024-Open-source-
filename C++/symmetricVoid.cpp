// Input : n = 2
// Output :  
//  x 
// x x 
//  x

// Input: n = 5
// Output:
//     x                                   
//      x 
//     o x 
//      o x 
// x o x o x 
//  x o 
//   x o 
//    x 
//     x 


// Input : n = 8;
// Output : 
//        x 
//         x 
//        o x 
//         o x 
//        x o x 
//         x o x 
//        o x o x 
// x o x o o x o x 
//  x o x o 
//   x o x 
//    x o x 
//     x o 
//      x o 
//       x 
//        x 



// Author:: Satish Srinivas
#include <iostream>

using namespace std;

// print alternate x o beginning with x
void printx(int n)
{
	for (int i = 1; i <= n; i++) {
		if (i % 2 != 0)
			cout << "x ";
		else
			cout << "o ";
	}
	return;
}

// print alternate x o beginning with o
void printo(int n)
{
	for (int i = 1; i <= n; i++) {
		if (i % 2 != 0)
			cout << "o ";
		else
			cout << "x ";
	}
	return;
}

// print the pattern for n
void Pattern(int n)
{
	// upper half
	int x = n;

	if (n % 2 == 0)
		x = x - 1;

	// number of spaces to leave in each line
	int p = n - 1;

	// number of characters in each line
	int s = 1;

	// prints double lines in each iteration
	for (int i = 1; i <= (x - 1) / 2; i++) {
		for (int j = 1; j <= p; j++) {
			cout << " ";
		}

		if (i % 2 != 0)
			printx(s);
		else
			printo(s);

		cout << endl;
		p++;

		for (int j = 1; j <= p; j++)
			cout << " ";	

		if (i % 2 != 0)
			printx(s);
		else
			printo(s);

		cout << endl;

		p--;
		s++;
	}

	// extra upper middle for even
	if (n % 2 == 0) {
		for (int i = 1; i <= p; i++)
			cout << " ";

		if (n % 4 != 0)
			printx(n / 2);
		else
			printo(n / 2);

		cout << endl;
	}

	// middle line
	if (n % 2 != 0)
		printx(n);
	
	else {
		if (n % 4 != 0) {
			printx(n / 2);
			printx(n / 2);
		}
		else {
			printx(n / 2);
			printo(n / 2);
		}
	}

	cout << endl;

	// extra lower middle for even
	if (n % 2 == 0) {
		cout << " ";
		printx(n / 2);
		cout << endl;
	}

	// lower half
	p = 1;

	if (n % 2 == 0) {
		x--;
		p = 2;
	}

	int q = x / 2;

	// one line for each iteration
	for (int i = 1; i <= x; i++) {
		for (int j = 1; j <= p; j++)
			cout << " ";

		printx(q);

		if (i % 2 == 0)
			q--;

		cout << endl;

		p++;
	}

	cout << endl;
}

int main()
{
	int n;
	cout<<"Enter a number : ";
	cin>>n;
	Pattern(n);
		return 0;
}

