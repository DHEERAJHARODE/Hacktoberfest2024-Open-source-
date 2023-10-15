
#include <iostream>
#include <conio>
using namespace std;
int main() {
   int n , fact = 1, i;
   cout<<"Enter a postive number"<<endl;
   cin>>n;
   for(i=1; i<=n; i++)
   fact = fact * i;
   cout<<"Factorial of "<<n<<" is "<<fact;
   return 0;
}
