#include <iostream>
#include <tuple>


using namespace std;

//Tuple Example

//make_tuple
//get<pos>(t1);

int main()
{
  
  tuple <string,int,int>t1;
  t1=make_tuple("Rab",2,3);
  
  
  cout<<get<0>(t1)<<endl;//pos 0
  cout<<get<1>(t1)<<endl; 
  cout<<get<2>(t1)<<endl;
    
}
