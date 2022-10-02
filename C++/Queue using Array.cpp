#include<iostream>
#define MAX 10
using namespace std;


class Queue
{
	public:
		int que[MAX];
		int front,rear;
		int data;
		
		Queue()
		{
			front=-1;
			rear=-1;
		}
		
		bool isEmpty()
		{
			if(front==-1)
			{
				return true;
			}
			
			else
			{
				return false;
			}
		}
		
		bool isFull()
		{
			if(rear==MAX-1)
			{
				return true;
			}
			
			else
			{
				return false;
			}
		}
		
		
		void enqueue();
		void dequeue();
		void display();
	
};

void Queue :: enqueue()
{
	if(isFull())
	{
		cout<<"\nQueue is Full";
	}
	
	else
	{
		cout<<"\nEnter element in queue: ";
		cin>>data;
		
		rear++;
		que[rear]=data;
		
		if(front==-1)
		{
			front=0;
		}
	}
	
}


void Queue :: dequeue()
{
	if(isEmpty())
	{
		cout<<"\nCan't perform delete operation\n";
	}
	
	else
	{
		int item=que[front];
		
		if(front==rear)
		{
			front=rear=-1;
		}
		
		else
		{
			front++;
		}
	}
}

void Queue :: display()
{
	
	if(isEmpty())
	{
		cout<<"\nQueue is empty";
	}
	
	else
	{
		for(int i=front;i<=rear;i++)
	    {
		    cout<<"| "<<que[i]<<" |";
	    }
	}

}


int main()
{
	Queue q;
	char start='y';
    int ch;
    
	
	while(start=='y')
    {
    	cout<<"\n1)Insert\n2)Delete\n";
    	cout<<"\nEnter your choice: ";
        cin>>ch;
        
    	 switch(ch)
         {
    	
    	    case 1:
    	    	q.enqueue();
    	    	q.display();
    	    	
    	    	break;

    		case 2:
    			q.dequeue();
    			q.display();
    		
    			break;
    			
    		default:
    		cout<<"\nSorry!!! you have entered wrong choice";
    	 }	
    	
    cout<<"\n\nDo you want to continue  (y/n): ";
    cin>>start;
    
	}
    
    cout<<"\nThank you!!!";
    
	return 0;
}
