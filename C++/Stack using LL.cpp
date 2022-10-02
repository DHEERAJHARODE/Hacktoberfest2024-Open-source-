#include<iostream>
using namespace std;

class node
{
	public:
		int data;
		node* next;	
};

class stack
{
	public:
		node* top;
		int len;
	
	stack() //Default constructor
	{
		top==NULL;
		len=0;
	
	}
	
	bool isEmpty()
	{
		if(top==NULL)
		{
			return true;
		}
		
		else
		{
			return false;
		}
	}
	

	void push();
	void pop();
	void display();
	
};

void stack :: push()
{

	node *temp;
	int add;
	
		temp=new node;
		cout<<"Enter value to be push: ";
		cin>>temp->data;
		temp->next=NULL;
		len++;
		
		if(top==NULL)
		{
			top=temp;
		}
		
		else
		{
			temp->next=top;
			top=temp; 
			
		}
		
}

void stack :: pop()
{
	if(top==NULL)
	{
		cout<<"\nStack is underflow";
	}
	
	else
	{
		top=top->next;
	}
}

void stack :: display()
{
	node *t=top;
	cout<<"\n";
	
	if(isEmpty())
	{
		cout<<"\nStack is empty";
	}
	
	
	else
	{
	   cout<<"\nYour stack is as follows: \n";
		
	   while(t!=NULL)
	   {
		  cout<<"\t"<<t->data<<"\n";
		  t=t->next;
	   }
   }
   
}



int main()
{
	int ch,val,start=1;
	
	stack s1;
	
	while(start==1)
	{
		cout<<"\n1)Push\n2)Pop\n3)isEmpty\n";
		cout<<"\nEnter your choice: ";
		cin>>ch;
		
		switch(ch)
		{
			case 1:
				s1.push();
				s1.display();
			    break;
			    
			case 2:
				s1.pop();
				s1.display();
				break;
			
			case 3:
				
				if(s1.isEmpty())
				{
					cout<<"\n\nStack is Empty";
				}
			    
			    else
			    {
			    	cout<<"\n\nStack is not Empty";
				}
				break;
			
		
			
			default:
			    cout<<"\nIncorrect choice !!";	
		}
		
		cout<<"\nEnter 1 to continue: ";
		cin>>start;
	}
	
	cout<<"\nThankyou !!!";
	
	return 0;
}
