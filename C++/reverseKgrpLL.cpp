#include <iostream>
using namespace std ;

class Node{
    public:
    int data;
    Node* next;

// CONSTRUCTOR    
Node(int data){
    this -> data = data ;
    this -> next = NULL;
}
};

void insertAtHead( Node* &head,int data){
    Node* New = new Node(data);
    New -> next = head ;
    head = New ;
};

void print(Node* head){
  Node* New = head ;
  while (New != NULL)
  {
    cout << New -> data << " ";
    New = New -> next ;
  }
  cout << endl ;
};

Node* reversekGroup(Node* head,int k){

    if (head == NULL )
    {
        return NULL ;
    }
    

  Node* forward = NULL ;
  Node* prev = NULL ;
  Node* current = head ;
  int count = 0;

  while (current != NULL && count < k)
  {
    forward = current -> next ;
    current -> next = prev ;
    prev = current ;
    current = forward ;
    count++;
  }

     if (forward != NULL )
    {
       head -> next = reversekGroup(forward,k);
    }    

  return prev ;

};

int main(){
    
    Node* head = NULL ;

    insertAtHead(head,10);
    print(head);

     insertAtHead(head,20);
    print(head);

 insertAtHead(head,30);
    print(head);

 insertAtHead(head,40);
    print(head);

   insertAtHead(head,50);
    print(head);
cout << " REVERSE "<<endl;
int k; cin >> k ;
head = reversekGroup(head,k);
print(head);
    return 0;
}