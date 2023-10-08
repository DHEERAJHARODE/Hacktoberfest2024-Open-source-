#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    Node* prev;
    Node* next;
    int data;
    //constructor
    Node(int d){
        this->data = d;
        this-> prev = NULL;
        this -> next = NULL;
    }
};

void print(Node* &head, Node* &tail)
{
    Node* temp = head;
   // int cnt = 0;
    while(temp != NULL)
    {
        cout<< temp -> data<<" "; 
        temp = temp -> next; 
       // cnt++;      
    }
    cout<<endl;
    cout<<"head = "<<head-> data<<endl;
    cout<<"tail = "<< tail -> data<<endl;
   // cout<<"length = "<<cnt;
   // cout<<endl;
}

void insertAtHead(Node* &head, int d)
{
    if(head == NULL)
    {
        Node* temp = new Node(d);
        head = temp;
    }
    else
    {
        Node* temp = new Node(d);
        temp -> next = head;
        head -> prev = temp;
        head = temp;
    }
}

void insertAtTail(Node* &tail, int d)
{
    Node* temp = new Node(d);

    tail -> next = temp;
    temp -> prev = tail;
    tail = temp;    
}

void insertAtPos(Node* &head, Node* &tail, int pos, int d)
{
    if(pos == 1)
    {
        insertAtHead(head, d);
        return;
    }

    Node* curr = head;
    int cnt =1;
    while(cnt < pos - 1)
    {
        curr = curr -> next;
        cnt++;
    }

    if(curr -> next == NULL)
    {
        insertAtTail(tail, d);
        return;
    }

    else
    {
        Node* temp = new Node(d);

        temp -> next = curr -> next;
        curr -> next -> prev = temp;
        curr -> next = temp;
        temp -> prev = curr;

    }

}

void deletion(Node* &head, Node* &tail, int pos)
{
    if(pos == 1)
    {
        Node* temp = head;
        head = head -> next;
        head -> prev = NULL;
        temp -> next = NULL;
        free(temp);
    }
    else
    {
        Node* curr = head;
        Node* prev = NULL;
        
        int cnt = 1;
        while(cnt < pos)
        {
            prev = curr;
            curr = curr -> next;
            cnt ++;
        }
        prev -> next = curr -> next;
        curr -> prev = NULL;
        curr -> next = NULL;
        free(curr);
        if(prev -> next == NULL)
        {
            tail = prev;
        }

    }
}


int main()
{
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    print(head, tail);
    insertAtHead(head, 13);
    print(head, tail);
    insertAtHead(head, 17);
    print(head, tail);

    insertAtTail(tail, 20);
    print(head, tail);
    insertAtTail(tail, 19);
    print(head, tail);

    insertAtPos(head, tail, 2, 11);
    print(head, tail);
    insertAtPos(head, tail, 1, 8);
    print(head, tail);
    insertAtPos(head, tail, 8, 9);
    print(head, tail);

    deletion(head, tail, 1);
    print(head, tail);
    deletion(head,tail, 7);
    print(head, tail);
    deletion(head, tail, 2);
    print(head, tail);
    deletion(head, tail, 5);
    print(head, tail);
    return 0;
}
