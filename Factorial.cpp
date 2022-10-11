
#include <iostream>
using namespace std;
int fact(){
   int f=1,n;
   cin>>n;
   for(int i=1;i<=n;i++){
      f=f*i;
   }
   cout<<"Factorial of "<<n<<" is "<<f; 
}
int main() {
   fact();
   return 0;
}
