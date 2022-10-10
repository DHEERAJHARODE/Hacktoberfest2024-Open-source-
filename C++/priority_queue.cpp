#include <bits/stdc++.h>
using namespace std;


typedef struct node{
    int data;
    int priority;
    node *link;
}node;

class Queue{
private:
    node *f;
public:
    Queue(){
        f = NULL;
    }
    void enqueue(int x, int p){
        node *temp = new node();
        temp->data = x;
        temp->priority = p;
        temp->link = NULL;
        if(f == NULL){
            f = temp;
        }else{
            node *curr = f;
            if(curr->priority > p){
                temp ->link = curr;
                f = temp;
            }else{
                while(curr->link != NULL && curr->link->priority <= p){
                    curr = curr->link;
                }
                temp->link = curr->link;
                curr->link = temp;
            }
        }
    }
    void dequeue(){
        if(f==NULL){
            cout<<"Queue Empty\n";

        }else{
            node *temp = f;
            f = f->link;
            delete temp;
        }
    }
    int fr(){
        return f->data;
    }
    bool isEmpty(){
        return (f==NULL);
    }
};

int main(){
    Queue q;
    q.enqueue(1,1);
    q.enqueue(2,1);
    q.enqueue(1,2);
    q.enqueue(6,3);
    q.enqueue(2,2);
    while(!q.isEmpty()){
        cout<<q.fr()<<"\n";
        q.dequeue();
    }

}
