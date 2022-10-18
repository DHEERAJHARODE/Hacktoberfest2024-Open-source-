#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node* next;

        node(int val){
            data = val;
            next = NULL;
        }
};

void InsertAtHead(node* &head, int val){
    node* n = new node(val);

    n->next=head;
    head=n;
}

void InsertAtTail(node* &head, int val){
    node* n = new node(val);

    node* temp = head;
    while(temp->next!=NULL){
        temp= temp->next;
    }

    temp->next=n;
}

void DeleteHead(node* &head){
    node* todelete = head;

    head=head->next;
    delete todelete;
}

void Deletion(node* &head, int val){
    if(head==NULL){
        return;
    }
    if(head->next==NULL){
        DeleteHead(head);
        return;
    }

    node* n = new node(val);

    node*temp = head;
    while(temp->next->data==val){
        temp=temp->next;
    }
    node* todelete = temp->next;
    temp->next = temp->next->next;

    delete todelete;
}

node* reverse(node* &head){
        node* prevptr = NULL;
        node* currptr = head;
        node* nextptr;

        while(currptr!=NULL){
            nextptr=currptr->next;
            currptr->next=prevptr;

            prevptr=currptr;
            currptr=nextptr;
        }
        return prevptr; //Because prevptr is new head at the end
}

node* RecursiveReverse(node* &head){
    if(head==NULL || head->next==NULL){
        return head;
    }

    node* newhead = RecursiveReverse(head->next);
    head->next->next=head;
    head->next= NULL;

    return newhead;
}

void display(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp= temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    node* head = NULL;
    InsertAtHead(head, 1);
    InsertAtTail(head, 2);
    InsertAtTail(head, 3);
    InsertAtTail(head, 4);
    InsertAtTail(head, 5);
    display(head);

    cout<<">>>>>>>After reversing<<<<<<<"<<endl;
    node* newhead = reverse(head);
    display(newhead);

    cout<<">>>>>>>>>>After recursive reverse<<<<<<<<<<"<<endl;
    node* headnew = RecursiveReverse(newhead);
    display(headnew);
    return 0;
}