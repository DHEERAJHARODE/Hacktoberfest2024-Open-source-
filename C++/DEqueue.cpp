#include<iostream>
using namespace std;
#define MAX 5

class dequeue
{
	public:
		int arr[MAX],data;
		int front,rear;
		
	dequeue()
	{
		front=rear=-1;
	}
	
	bool isEmpty()
	{
		if(rear==-1)
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
		if((rear+1)%MAX==front)
		{
			return true;
		}
		
		else
		{
			return false;
		}
	}
	
	
	void enqueue_front();
	void enqueue_rear();
	void dequeue_front();
	void dequeue_rear();
    void display();
};

void dequeue :: enqueue_front()
{
	if(isFull())
	{
		cout<<"\nDequeue is Full\n";
	}
	
	else
	{
		cout<<"\nEnter element in queue: ";
		cin>>data;
		
		front=(front-1+MAX)%MAX;
		arr[front]=data;
		
		if(rear==-1)
		{
			rear=0;
		}
	}
}


void dequeue :: enqueue_rear()
{
	if(isFull())
	{
		cout<<"\nDequeue is Full";
	}
	
	else
	{
		cout<<"\nEnter element in queue: ";
		cin>>data;
		
		rear=(rear+1)%MAX;
		arr[rear]=data;
		
		if(front==-1)
		{
			front=0;
		}
		
	}
}


void dequeue :: dequeue_front()
{
	if(isEmpty())
	{
		cout<<"\nDequeue is empty";
	}
	
	else
	{
		int x=arr[front];
		
		if(front==rear)
		{
			front=rear=-1;
		}
		
		else
		{
			front=(front+1)%MAX;
		}
		
	}
}


void dequeue :: dequeue_rear()
{
	if(isEmpty())
	{
		cout<<"\nDequeue is empty";
	}
	
	else
	{
		int x=arr[rear];
	
		if(front==rear)
		{
			front=rear=-1;
		}
		
		else if(rear==0)
		{
			rear=MAX-1;
		}
		
		else
		{
			--rear;
		}
		
	}
}


void dequeue :: display() 
{
	int f=front;
	int r=rear;
	
	
	if(isEmpty())
	{
		cout<<"\nDequeue is empty";
	}
	
	if(f <= r) 
	{
        while (f <= r)
	    {
            cout<<"| "<<arr[f]<<" |";
            f++;
        }
    } 
	
	else 
	{
        while (f <= MAX - 1) 
		{
            cout<<"| "<<arr[f]<<" |";
            f++;
        }
        
        f = 0;
        
        while (f <= r)
		{
            cout<<"| "<<arr[f]<<" |";
            f++;
      
	    }
    }

}



int main()
{
	dequeue dq;
	char start='y';
    int ch;
    
	
	while(start=='y')
    {
    	cout<<"\n1. Insert at rear\n2. Insert at front\n3. Delete from front\n4. Delete from end";
    	cout<<"\n\nEnter your choice: ";
        cin>>ch;
        
    	 switch(ch)
         {
    	
    	    case 1:
    	    	dq.enqueue_rear();
    	    	dq.display();
    	    	
    	    	break;

    		case 2:
    			dq.enqueue_front();
    			dq.display();
    		
    			break;
    		
			case 3:
			    dq.dequeue_front();
			    dq.display();
			    
			    break;
			
			case 4:
			    dq.dequeue_rear();
				dq.display();
				
				break;
			
			case 5:
			    dq.display();
				
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
