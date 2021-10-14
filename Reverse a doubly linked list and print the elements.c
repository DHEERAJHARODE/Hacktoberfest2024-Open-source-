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
void Reverse(struct Node *p)
{
struct Node *temp;
while(p!=NULL)
{
temp=p->next;
p->next=p->prev;
p->prev=temp;
p=p->prev;
if(p!=NULL && p->next==NULL)
first=p;
}
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
    printf("\nDoubly linked list are: ");
    for(i=0;i<n;i++)
 
    {
        printf("%d  ", arr[i]);
    }
 
create(arr,n);
Reverse(first);
printf("\nReversed Doubly linked list : ");
Display(first);
}
