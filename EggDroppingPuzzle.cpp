#include<bits/stdc++.h>
using namespace std ;
int eggdrop(int n , int k )
{
   int dp[n+1][k+1] ;
   for (int i = 1; i <= n; i++)
   {
       dp[i][0]= 0;
       dp[i][1]= 1;
   }
   for (int i = 1; i <= k; i++)
   {
       dp[1][i]= i; 
   }
   int i,j,x ,res ;
   for ( i = 2; i <=n; i++)
   {
       for ( j = 2; j <= k ; j++)
       {
           dp[i][j]= INT_MAX ;
           for ( x =1; x <=j ; x++)
           {
               res =1+ max(dp[i-1][x-1] , dp[i][j-x]);
               if (dp[i][j]> res )
               {
                   dp[i][j]= res; 
               }       
           }
       }
   }
   return dp[n][k] ;
    
}
int main()
{
       int n=2, k=36;
       cout<<"Minimum number of trials in worst case : "<<eggdrop(n,k)<<endl;
}