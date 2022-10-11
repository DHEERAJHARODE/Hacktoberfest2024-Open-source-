import java.util.*;
public class spiral 
{
  public static void main(String[] args) 
  { 
     Scanner sc=new Scanner(System.in);
     int n,i,j,k=1,g,r=0,c=-1,d=1; 
     System.out.println("Enter the length of the array.");
     n=sc.nextInt(); 
     g=n; 
     int a[][]=new int[n][n]; // initialising array
     while(k<=(n*n)) 
     {
         for(i=1;i<=g;i++) // storing the values according to spiral pattern
         a[r][c=c+d]=k++;
         for(i=1;i<g;i++)
         a[r=r+d][c]=k++;
         g--; // decrementing
         d=-d; 
     } 
     for(i=0;i<n;i++)
     {
         for(j=0;j<n;j++)
         {
             if(a[i][j]<10) // condition for when a number is lesser than 10 
             System.out.print(a[i][j]+"  "); 
             else // condition for when a number is lesser than 10 
             System.out.print(a[i][j]+" "); 
         System.out.println(); // shifting the cursor to the next line
     }
  } 
} 
}
