#include<iostream>
#define MAX 5
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
			if( (front==0 && rear==MAX-1)  || (front==rear+1) )
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
		cout<<"\nQueue is Full\n";
	}
	
	else
	{
		cout<<"\nEnter element in queue: ";
		cin>>data;
	
		if(front==-1)
		{
			front=rear=0;
		}
		
		else
		{
			rear=(rear+1)%MAX;
		}
		
		que[rear]=data;
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
			front=(front+1)% MAX;
		}
	}
}

void Queue :: display()
{
	int f=front;
	int r=rear;
	
	
	if(isEmpty())
	{
		cout<<"\nQueue is empty";
	}
	
	if(f <= r) 
	{
        while (f <= r)
	    {
            cout<<"| "<<que[f]<<" |";
            f++;
        }
    } 
	
	else 
	{
        while (f <= MAX - 1) 
		{
            cout<<"| "<<que[f]<<" |";
            f++;
        }
        
        f = 0;
        
        while (f <= r)
		{
            cout<<"| "<<que[f]<<" |";
            f++;
      
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
    	cout<<"\n------------------------------------";
    	cout<<"\n1. Insert\n2. Delete\n3. Display";
    	cout<<"\n------------------------------------";
    	cout<<"\n\nEnter your choice: ";
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
    		
			case 3:
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
