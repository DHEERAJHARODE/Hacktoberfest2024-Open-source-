#include<stdio.h>
#define MAX 100

int insert_array(int a[]) {
  int n, i;
  printf("Quanti elementi?: ");
  scanf("%d", &n);

  for (i=0; i<n; i++) {
  	 printf("elemento %d: ", i);
  	    scanf("%d", &a[i]);
  }
  return(n);
}

void stampa_array(int a[], int n) {
  int i;
  for (i=0; i<n; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
  return;
}

void quicksort(int a[MAX],int primo,int ultimo){
   int i, j, pivot, temp;

   if(primo<ultimo){
      pivot=primo;
      i=primo;
      j=ultimo;     
      
      while(i<j){
         while(a[i]<=a[pivot]&&i<ultimo)
            i++;
         while(a[j]>a[pivot])
            j--;
         if(i<j){   
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
         }
      }

      temp=a[pivot];
      a[pivot]=a[j];
      a[j]=temp;
      quicksort(a,primo,j-1);
      quicksort(a,j+1,ultimo);
   }
}

int main(){
   int n, a[MAX],i;
   n = insert_array(a);
   printf("Array iniziale: "); 
   stampa_array(a,n);    
   quicksort(a,0,n-1);
   printf("Array ordinato con quick-sort: ");
   stampa_array(a,n);
   return 0;
}
