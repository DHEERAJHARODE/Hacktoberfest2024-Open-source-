#include <iostream>
#include <string>
using namespace std;

struct node{
    char data;
    node *next;
    node *prev;
};
node *head=NULL;

void print()
{
    node* ptr=head;

    for( ; ptr!=NULL; ptr=ptr->next)
    {
        cout<<ptr->data;
    }
    cout<<endl;
}

void insert(char ch)
{
    node *newnode= new node;
    newnode->data=ch;
    newnode->next=NULL;

    //if the linked list is empty
    if(head==NULL)
    {
        //this means no head node exists so set the new node as the head
        newnode->prev=NULL;
        head=newnode;
        return;
    }

    else
    {
        node *ptr=head;
        //finding the end of the current list
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;//ptr is now the last node in the list
        }
        ptr->next=newnode;//at the NULLth position we insert the new node and update the NULL to the next position
        newnode->prev=ptr;
    }
}

int checkPalin()
{
    if(head==NULL)
        return true;
    
    node *ptr=head;

    while(ptr->next!=NULL)
    {
        ptr=ptr->next;    
    }
    
    node *temp=head;    
    
    while(ptr!=temp)
    {
        if(temp->data!=ptr->data)
        {
            return 0;            
        }
        temp=temp->next;
        ptr=ptr->prev;
    }
    return 1;
}

int main()
{
    string st;
    cout<<"Enter the String to be checked: "<<endl;
    cin>>st;

    for(int i=0;i<st.length();i++)
    {
        insert(st.at(i));
    }
    if(checkPalin()==1)
    cout<<"\nPalindrome";
    else if(checkPalin()==0)
    cout<<"\nNot Palindrome";
}
