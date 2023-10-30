#include<iostream>

using namespace std;

#define SIZE 3

int arr[SIZE];
int front = -1;
int rear  = -1;

bool isQueueFull()
{
    if(front == 0 && rear == SIZE - 1)
        return true;

    if(rear == front - 1)
        return true;

    return false;
}

void enQueue(int val)
{
    if(isQueueFull())
    {
        cout<<"Circular Queue is Full: Unable to Insert Element: "<<val<<endl;
    }
    else
    {
        if(front == -1)
            front = 0;

        rear = (rear + 1) % SIZE;
        arr[rear] = val;

        cout<<"Inserted Element = "<<val<<endl;
    }
}

bool isQueueEmpty()
{
    if(front == -1)
        return true;
    
    return false;
}

int deQueue()
{
    if(isQueueEmpty())
    {
        cout<<"Circular Queue is Empty"<<endl;
        return -1;
    }
    else
    {
        int val = arr[front];

        if(front == rear)
        {
            front = -1;
            rear  = -1;
        }
        else
            front = (front + 1) % SIZE;

        return val;
    }
}

int main()
{
    cout<<"Initial: ";
    int val = deQueue();
    
    cout<<"Enqueue(10): ";
    enQueue(10);
    cout<<"Enqueue(20): ";
    enQueue(20);
    cout<<"Enqueue(30): ";
    enQueue(30);
    
    cout<<"Enqueue(40): ";
    enQueue(40);    

    cout<<"Dequeue(): ";
    val = deQueue();
    if(val != -1)
        cout<<"Dequeued Element = "<<val<<endl;

    cout<<"Enqueue(40): ";
    enQueue(40);
    
    cout<<"Enqueue(50): ";
    enQueue(50);

    cout<<"Dequeuing all the elements:"<<endl;

    cout<<"Dequeue(): ";
    val = deQueue();
    while(val != -1)
    {
        if(val != -1)
            cout<<"Dequeued Element = "<<val<<endl;

        cout<<"Dequeue(): ";
        val = deQueue();
    }
    
    return 0;
}