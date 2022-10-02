#include<iostream>
#define MAX 10
using namespace std;

//-------------------Queue using Array------------------

class Queue_array
{
	public:
		int que[MAX];
		int front,rear;
		int data;
		
		Queue_array()
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

void Queue_array :: enqueue()
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


void Queue_array :: dequeue()
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

void Queue_array :: display()
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



//-----------------------Queue using LL---------------------


class node
{
	public:
		int data;
		node *next;
		
};

class Queue_LL
{
	public:
		node *front, *rear;
	
	Queue_LL()
	{
		front=NULL;
		rear=NULL;
	}
	
	bool isEmpty()
	{
		if(front==NULL)
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

void Queue_LL :: enqueue() //enqueue
{
	node *temp;
	temp=new node;
	
	cout<<"\nEnter data: ";
	cin>>temp->data;
	temp->next=NULL;
	
	if(rear==NULL)
	{
	    front=rear=temp;
	  
	}
	
	else
	{
		rear->next=temp;
		rear=rear->next;
	}
	
}

void Queue_LL :: dequeue() //dequeue
{
	if(isEmpty())
	{
		cout<<"\nCan't perform delete operation";
	}
	
	else
	{
		int x=front->data;
    
        if(front==rear)
        {
    	    front=rear=NULL;
	    }
	
	    else
	    {
		    front=front->next;
		    delete front;
	    }
	}
	
}

void Queue_LL :: display() //display
{
	if(isEmpty())
	{
		cout<<"\nQueue is Empty";
	}
	
	node *ptr;
	ptr=front;
	
	cout<<"\n";
	while(ptr!=NULL)
	{
		cout<<"| "<<ptr->data<<" |";
		ptr=ptr->next;
	}
	
}

int main()
{
	char start='y';
    int ch,ch1,ch2;
    
	Queue_array q1; //object for array
	
	Queue_LL q2; //object for linked list
	
	while(start=='y')
	{
		cout<<"1. Queue using array\n2. Queue using Linked list";
		cout<<"\n\nEnter your choice: ";
		cin>>ch;
		
		switch(ch)
		{
			case 1:
				
				while(start=='y')
                {
    	            cout<<"\n1)Insert\n2)Delete\n";
    	            cout<<"\nSelect operation: ";
                    cin>>ch;
        
    	            switch(ch)
                    {
    	
    	                case 1:
    	    	            q1.enqueue();
    	    	            q1.display();
    	    	
    	    	            break;

    		            case 2:
    			            q1.dequeue();
    			            q1.display();
    		
    			            break;
    			
    		            default:
    		                cout<<"\nSorry!!! you have entered wrong choice";
    	            }	
    	
                    cout<<"\n\nDo you want to continue with array implementation (y/n): ";
                    cin>>start;
    
	           }
	            break;
	            
	        case 2:
	        	while(start=='y')
                {
    	            cout<<"\n1)Insert\n2)Delete\n";
    	            cout<<"\nSelect operation: ";
                    cin>>ch;
        
    	            switch(ch)
                    {
    	
    	                case 1:
    	    	            q2.enqueue();
    	    	            q2.display();
    	    	
    	    	            break;

    		            case 2:
    			            q2.dequeue();
    			            q2.display();
    		
    			            break;
    			
    		            default:
    		                cout<<"\nSorry!!! you have entered wrong choice";
    	            }	
    	
                    cout<<"\n\nDo you want to continue with Linked list implementation (y/n): ";
                    cin>>start;
    
	           }
	            break;
	        
			default:
    		    cout<<"\nSorry!!! you have entered wrong choice";	
	    }
	    
		cout<<"\n\nBack to implementation choice (y/n): \n";
        cin>>start;
   }
	
	cout<<"\nThank you !!!";
	
	return 0;
}

