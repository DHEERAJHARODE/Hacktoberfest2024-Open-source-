#include <stdio.h> 
int main() 
{
  printf("Hello World!\n" );
  int n;
  printf ( "How many numbers you want to enter :");
  scanf ("%d", &n);
  int x[n];
  int i;
  for(i=0;i<n;i++)
  {
    printf("Enter No %d: ",i+1); 
    scanf("%d",&x[i]);
  }
  int max=x[0];
  for(i=1;i<n;i++)
  {
    if (x[i]>max)
    {
      max=x [i];
    }
  }
printf ("max is %d\n", max);
 return 0;
}
