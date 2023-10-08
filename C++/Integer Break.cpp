** PROBLEM STATEMENT **
  
Given an integer n, break it into the sum of k positive integers, where k >= 2, and maximize the product of those integers.
Return the maximum product you can get.
  
** EXAMPLE INPUT **
Example 1:
  
Input: n = 2
Output: 1
Explanation: 2 = 1 + 1, 1 × 1 = 1.

Example 2:

Input: n = 10
Output: 36
Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.

**Constraints:**

2 <= n <= 58

  
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
  
  ** SOLUTION **

 int solve(int n)
 {
     int ans=1;
     while(n>=3)
     {
         ans*=3;
         n-=3;
     }
     if(n==1)
     {
         ans/=3;
         ans*=4;
     }
     else if(n>0)
     ans*=n;
     return ans;
 }
    int main() {
      int n;
      cin>>n;
       if(n==2)
         cout<< 1 <<endl;
       if(n==3)
         cout<< 2 <<endl;

      cout<< solve(n)<<endl;
      return 0;
    }
