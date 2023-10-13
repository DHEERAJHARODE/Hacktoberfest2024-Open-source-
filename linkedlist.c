#include<iostream>
using namespace std;

class LinkedListNode{
    public:
    int data;
    LinkedListNode*next;

    LinkedListNode(int data){

        this->data=data;
        this->next=NULL;
    }

}

int main(){

    LinkedListNode*node1=new LinkedListNode(10);
    cout<<node1->data<<endl;
    cout<<node1->next<<endl;

    return 0;
}
