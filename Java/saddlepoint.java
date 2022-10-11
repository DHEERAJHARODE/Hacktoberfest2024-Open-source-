import java.util.*;
public class saddlepoint 
{
 public static void main(String[] args) 
 {
  Scanner sc=new Scanner (System.in);
  int i,j,r,c,min,p,max,f=0,sp=0; // declaring and initialising variables
  System.out.println("Enter the number of rows."); 
  r=sc.nextInt(); // taking input
  System.out.println("Enter the number of columns."); 
  c=sc.nextInt(); 
  int a[][]=new int[r][c]; // initialising array
  System.out.println("Enter the elements into the array."); 
  for(i=0;i<r;i++)
  { 
    for(j=0;j<c;j++)
     a[i][j]=sc.nextInt();
  }
  System.out.println(); // shifting cursor to the next line
  for(i=0;i<r;i++) // loop to print the array
  { 
    for(j=0;j<c;j++)
     System.out.print(a[i][j]+" "); 
    System.out.println(); // shifting cursor to the next line
  }
  System.out.println(); // shifting cursor to the next line
  for(i=0;i<r;i++)
  { 
     p=0; // initialising variables
     min=a[i][0]; 
     for(j=0;j<c;j++) // finding the smallest number in each row
     { 
        if(a[i][j]<min)
        {
            min=a[i][j];
            p=j;
        }
     }
     max=0; // initialising variable
     for(j=0;j<r;j++) /* finding the largest number in the column in
                         which the smallest number of the row exists */
     {
        if(a[j][p]>max)
          max=a[j][p];
     }
     if(min==max) // checking whether a saddle point exists or not
     {
        f++; // incrementing to signify that saddle point exists
        sp=min; // storing value of saddle point
        break; // break statement
     }
  } // closing i loop
  if(f>0) // condition for when saddle point exists
   {
    System.out.println("A saddle point exists."); 
    System.out.println("The saddle point is "+sp+"."); 
   }
  else // condition for when saddle point doesn't exist
  System.out.println("A saddle point doesn't exist."); 
 } 
} 
            

