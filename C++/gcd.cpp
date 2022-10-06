//C++ program to find greatest HCF or Greatest Common Divisor(GCD)
#include <iostream>
using namespace std;

int main()
{
   int x, y, i, gcd;

   cout << "Enter two integer values:" << endl;
   cin >> x >> y;

   for (i = 1; i <= x && i <= y; i++)
   {
      if (x % i == 0 && y % i == 0)
         gcd = i;
   }

   cout << "\nGCD of " << x << " and " << y << " is: " << gcd << endl;

   return 0;
}
