#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

class cir_linklist
{
private:
    Node *head;

public:
    cir_linklist()
    {
        head = NULL;
    }
    void inBeg(int value);
    void inAny(int pos, int value);
    void display();
    void delBeg();
    int count();
    void delAny(int pos);
};
int cir_linklist :: count(){
    int c=0;
    if (head==NULL)
    {
        return c;
    }
    else{
        c++;
    Node* p=head;
    while (p->next != head)
    {
         p = p->next;
         c++;
    }
    return c;
    }
}

void cir_linklist ::inBeg(int value)
{

    if (head == NULL)
    {
        head = new Node(value);
        head->next=head;
    }

    else
    {
        Node *p = head;
        Node *t = new Node(value);
        t->next = head;
        while (p->next != head)
        {
            p = p->next;
        }
        p->next = t;
        head = t;
        
    }
    cout<<"The value is inserted"<<endl;
}

void cir_linklist ::display()
{
    Node *p = head;
    if (head != NULL)
    {

        do
        {
            cout << p->data << "\t";
            p = p->next;
        } while (p != head);
    }
    else
    {
        cout << "The list is empty" << endl;
    }
}

void cir_linklist :: inAny(int pos,int value){
    if (pos<0||pos>count())
    {
        cout<<"invalid position"<<endl;
    }
    else
    {
        if (pos==0)
        {
            inBeg(value);
        }
        else
        {
            Node* t=new Node(value);
            Node* p = head;
            for (int i = 0; i < pos-1; i++)
            {
                p=p->next;
            }
            t->next=p->next;
            p->next=t;
            
        }
        
    }
    
    
}

void cir_linklist :: delBeg(){
    if (head->next!=head)
    {
            
    Node* p= head;
    while (p->next!=head)
    {
        p=p->next;

    }
    p->next=head->next;
    delete head;
    head = p->next;
    }
    else if(head==NULL){
        cout<<"The list is empty can\'t delete"<<endl;
    }
    else{
        head=NULL;
    }

    
}

void cir_linklist :: delAny(int pos){
    if (pos<0&&pos>count())
    {
        cout<<"invalid position"<<endl;
    }
    else
    {
        if (pos==0)
        {
            delBeg();
        }
        else
        {
            Node* p=head;
            for (int i = 0; i < pos-1; i++)
            {
                p=p->next;
            }
            Node* q=p->next;
            p->next=q->next;
            delete q;
            
        }
        
    }
    
    
}

int main()
{
    cir_linklist s;

    s.inBeg(3);
    s.inBeg(2);
    s.inBeg(1);
    cout<<s.count()<<endl;
    s.display();
    cout<<endl;
    s.inAny(2,4);
    s.display();
    s.delAny(3);
    cout<<endl;
    s.display();
    return 0;
}