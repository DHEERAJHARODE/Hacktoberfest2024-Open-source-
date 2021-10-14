#include <stdio.h>
#include<stdlib.h>
struct Node
{
struct Node *prev;
int data;
struct Node *next;
}*first=NULL;
void create(int A[],int n)
{
struct Node *t,*last;
int i;
first=(struct Node *)malloc(sizeof(struct Node));
first->data=A[0];
first->prev=first->next=NULL;
last=first;
for(i=1;i<n;i++)
{
t=(struct Node *)malloc(sizeof(struct Node));
t->data=A[i];
t->next=last->next;
t->prev=last;
last->next=t;
last=t;
}
}
void Display(struct Node *p)
{
while(p)
{

printf("%d ",p->data);
p=p->next;
}
printf("\n");
}
int Length(struct Node *p)
{
int len=0;
while(p)
{
len++;
p=p->next;
}
return len;
}

int Delete(struct Node *p,int index)
{
int x=-1,i;
if(index < 1 || index > Length(p))
return -1;
if(index==1)
{
first=first->next;
if(first)first->prev=NULL;
x=p->data;
free(p);
}
else
{
for(i=0;i<index-1;i++)
p=p->next;
p->prev->next=p->next;
if(p->next)
p->next->prev=p->prev;
x=p->data;
free(p);
}
return x;
}
int main(){

int arr[100],i,n; 
    printf("Enter the size of the Doubly linked list\n");  
    scanf("%d",&n);  
    printf("Enter the elements of the Doubly linked list\n");  
    for(i = 0; i<n; i++)  
    {  
        scanf("%d",&arr[i]);  
        
    } 
    printf("\nElements in Doubly linked list are: ");
    for(i=0;i<n;i++)
 
    {
        printf("%d  ", arr[i]);
    }
 
create(arr,n);

printf("\nSelect from the following Deleting options\n");
                 	printf("1. At Beginning\n2. At End\n3. Particular element\n");
                 	int choice;
                    scanf("%d",&choice);
                    switch(choice)
                    {
                       case 1: 	Delete(first,1);
                                printf("Doubly linked list after deleting at beginning\n");
                                Display(first);
                       		break;
                       case 2: 	Delete(first,n);
                                printf("Doubly linked list after deletingat end\n");
                                Display(first);
                       		break;
                       case 3: 	printf("Enter  the element which you want to delete: ");
                            int element ;
                       		scanf("%d",&element);
                       		Delete(first,element);
                       		printf("Doubly linked list after deleting the particular element\n");
                       		Display(first);
                       		break;
                       default: printf("\nPlease select correct deleting option!!!\n");
                    }
                 }
