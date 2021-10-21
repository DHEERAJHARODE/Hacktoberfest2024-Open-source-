#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

void insertatTail(Node* &head, int val){
    Node* n = new Node(val);
    if(head == NULL){
        head = n;
        return;
    }

    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
}

void makeCycle(Node* &head, int pos){
    Node* temp = head;
    Node* startNode;

    int count = 1;

    while(temp->next!=NULL){
        if(count==pos)
            startNode = temp;
        temp = temp->next;
        count++;
    }
    temp->next = startNode;
}

void display(Node* head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head = head->next;
    }
    cout<<"NULL"<<endl;
}

bool detectCycle(Node* &head){
    Node* slow = head;
    Node* fast = head;

    while(fast!=NULL && fast->next!=NULL)/*We will check for 
    case when there is no cycle (fast is always ahead of slow)*/
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow==fast){
            return true;
        }
    }
    return false;
}

int main(){
    Node* head = NULL;
    insertatTail(head, 1);
    insertatTail(head, 2);
    insertatTail(head, 3);
    insertatTail(head, 4);
    insertatTail(head, 5);
    insertatTail(head, 6);
    insertatTail(head, 7);
    insertatTail(head, 8);
    insertatTail(head, 9);
    
    makeCycle(head, 4);
    // display(head);

    cout<<detectCycle(head)<<endl;

}
