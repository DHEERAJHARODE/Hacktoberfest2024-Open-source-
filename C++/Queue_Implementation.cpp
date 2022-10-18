#include<iostream>
using namespace std;

class Node 
{
public:
    int data;
    Node* next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

class Queue
{
public:
    Node* front;
    Node* rear;
    Queue()
    {
        front = NULL;
        rear = NULL;
    }
    void enqueue(int d)
    {
        Node* temp = new Node(d);
        if (rear == NULL) 
        {
            front = rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }
    void dequeue()
    {
        if (front == NULL)
        {
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == NULL)
        {
            rear = NULL;
        }
        delete(temp);
    }
    int Front()
    {
        if (front == NULL)
        {
            cout << "Queue is empty\n";
        }
        return front->data;
    }
    bool isEmpty()
    {
        if (front == rear == NULL)
        {
            return true;
        }
        return false;
    }
    void print()
    {
        Node* temp = front;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};
int main()
{
    Queue obj;
    obj.enqueue(10);
    obj.enqueue(20);
    obj.enqueue(30);
    obj.print();
    cout << "\nDeleting....\n";
    obj.dequeue();
}