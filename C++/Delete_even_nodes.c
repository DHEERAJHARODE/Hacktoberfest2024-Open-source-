#include<iostream>
using namespace std;
struct node
{
           int data;
           node *next;
};
node* insert_node(node *start,int x)
{
           node *temp=new node;
           temp->data=x;
           temp->next=NULL;
           if(start==NULL)
                      return temp;
           node *ptr=start;
           while(ptr->next!=NULL)
           {
                      ptr=ptr->next;
           }
           ptr->next=temp;
           return start;
}
void display(node *start)
{
           node *temp=start;
           while(temp!=NULL)
           {
                      cout<<temp->data<<" ";
                      temp=temp->next;
           }
}
node* delete_even(node *start)
{
           node *even=start->next;
           node *odd=start;
           while(even!=NULL && odd!=NULL)
           {
                      odd->next=even->next;
                      free(even);
                      odd=odd->next;
                      if(odd!=NULL)
                                 even=odd->next;
           }
           return start;
}
int main()
{
           node *sample=NULL;
           sample=insert_node(sample,10);
           sample=insert_node(sample,20);
           sample=insert_node(sample,30);
           sample=insert_node(sample,40);
           display(sample);
           sample=delete_even(sample);
           cout<<"\nAfter deletion:";
           display(sample);
           return 0;
}
