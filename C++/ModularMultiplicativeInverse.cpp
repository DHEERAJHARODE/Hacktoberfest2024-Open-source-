/*

Consider P to be a Prime and A to be a integer. 
B is called the modular multiplicative inverse of A under modulo P if B*A % P = 1.
OR
AB ≡ 1 (mod P)
Here '≡' denotes congruence.

Note: If P is not a Prime, then the modular inverse of A may not exist.

Applications of Modular Multiplicative Inverse can be found in many problems of Number Theory. 
This can be used in Competitive Programming and Cryptography.

*/

// C++ program to find modular inverse of A under modulo P
#include <bits/stdc++.h>
using namespace std;

// Method 1: A naive method to find modular multiplicative inverse of 'A' under modulo 'P'
    // time complexity: O(P)
    // Auxiliary Space: O(1)
int modInverseNaive(int A, int P)
{

    A = A % P;
    for (int X = 1; X < P; X++)
        if (((A % P) * (X % P)) % P == 1)
            return X;
}



/* 
The extended Euclidean algorithm gives us an efficient computational method for computing A^−1 mod P. 
We simply solve the equation
Au + Pv = 1 in integers u and v; (Note : A and P are relatively prime (P is a prime number anyway), 
had they not been, the formula changes to Au +Pv = gcd(A,P) and gcd(A,P) should be 1 for the inverse to exist)
*/

// Method 2: Using Extended Euclidean Algorithm
/*
    The function returns integer x such that Ax + By = gcd(A, B)
    It also stores values of coefficients x and y in variables x and y
    gcd(A, B) is the greatest common divisor of A and B
*/

    // time complexity: O(log(min(A, P)))
    // Auxiliary Space: O(1)
int gcdExtended(int A, int P, int *X, int *Y)
{
    // Base Case
    if (A == 0)
    {
        *X = 0;
        *Y = 1;
        return P;
    }

    int X1, Y1; // To store results of recursive call
    int gcd = gcdExtended(P % A, A, &X1, &Y1);

    // Update X and Y using results of recursive call
    *X = Y1 - (P / A) * X1;
    *Y = X1;

    return gcd;
}

// Driver code
int main()
{
	int A = 3, P = 11;
    int X, Y;
	// Function call
	cout << modInverseNaive(A, P)<<"\n";
    cout <<"The modular multiplicative inverse is "<< gcdExtended(A, P, &X, &Y)<<"\n";
	return 0;
}

//You can read the textbook on "Introduction to Mathematical Cryptography" by Silverman and Hoffstein for a better understanding of the topic!"