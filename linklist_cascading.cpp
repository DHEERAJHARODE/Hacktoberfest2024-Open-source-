#include <iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node(int value){
        data=value;
        next = nullptr;
    }
};

class Linklist
{
private:
    Node* head;
public:
    Linklist(){
        head=NULL;
    };
    void inBeg(int value);
    void display();
    Node* getHead();
};

void Linklist ::inBeg(int value)
{
    Node *temp = new Node(value);
    temp->next = head;
    head = temp;
    cout << "The value is inserted" << endl;
}

void Linklist ::display()
{
    cout << "The items are" << endl;
    Node *current = head;
    while (current != NULL)
    {
        cout << current->data << "\t";
        current = current->next;
    }
}

Node* Linklist :: getHead(){
    return head;
}

void concat(Linklist p,Linklist q){
    Node* curr = p.getHead();
    while (curr->next)
    {
        curr=curr->next;
    }
    curr->next=q.getHead();
    
}

int main(void){
    Linklist p;
    Linklist q;
    p.inBeg(4);
    p.inBeg(3);
    p.inBeg(2);
    p.inBeg(1);
    p.display();
    cout<<endl;
    q.inBeg(8);
    q.inBeg(7);
    q.inBeg(6);
    q.inBeg(5);
    q.display();
    cout<<endl;
    concat(p,q);
    p.display();
    
    return 0;
}
