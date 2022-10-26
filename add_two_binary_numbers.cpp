#include<iostream>
using namespace std;

int main()
{
   string bin1, bin2, addRes;
   int len, carry, re, i;
   cout<<"Enter First Binary Number: ";
   cin>>bin1;
   cout<<"Enter Second Binary Number: ";
   cin>>bin2;
   len = bin1.size();
   addRes = "";
   carry = 0;
   for(i=(len-1); i>-1; i--)
   {
      re = carry;
      if(bin1[i] == '1')
         re = re+1;
      else
         re = re+0;
      if(bin2[i] == '1')
         re = re+1;
      else
         re = re+0;
      if(re%2==1)
         addRes = '1' + addRes;
      else
         addRes = '0' + addRes;
      if(re<2)
         carry = 0;
      else
         carry = 1;
   }
   if(carry!=0)
      addRes = '1' + addRes;
   cout<<"\nAddition Result = "<<addRes;
   return 0;
}
