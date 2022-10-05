#include <iostream>
using namespace std;

class Node {
    
    public:
        int data;
        Node* next;

        //constructor

    Node(int data){
        this -> data = data;
        this -> next = NULL;

    }

    //destructor
    ~Node(){
        int value = this -> data;

        if(this -> next != NULL){
            delete next;
            this -> next = NULL;
        }
    }

};

void insertAtHead(Node* &head, int data){

    //create a new node
    Node* temp = new Node(data);

    //pointing to head
    temp -> next = head;

    //making new head
    head = temp;
}

void print(Node* &head){
    Node* temp = head;

    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

void insertAtTail(Node* &tail, int data){
    Node* temp = new Node(data);
    tail -> next = temp;
    tail = temp;
}

void insertInMiddle(Node *&head, Node *&tail, int pos, int data)
{
    if(pos == 1){
        insertAtHead(head, data);
        return ;
    }
    Node* temp = head;
    int cnt = 1;

    while(cnt < pos - 1){
        temp = temp->next;
        cnt ++;
    }
    if(temp -> next == NULL){
        insertAtTail(tail, data);
        return ;
    }
    Node* nodeToInsert = new Node(data);
    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;
}

void deleteNode(Node* &head, int pos){
    if(pos == 1){
        Node* temp = head;
        head = head -> next;
        temp -> next = NULL;
        delete temp;
    }
    else{

        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < pos){
            prev = curr;
            curr = curr-> next;
            cnt ++;
        }
        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
    }
}

int main(){

    Node* n1 = new Node(10);
    Node* head = n1;
    Node* tail = n1;
    // print(head);

    insertAtHead(head, 30);
    insertAtHead(head, 40);

    print(head);
    insertInMiddle(head, tail, 4, 20);
    print(head);

    deleteNode(head, 1);
    print(head);
    
    return 0;
    
}
