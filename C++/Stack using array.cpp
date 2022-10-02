#include<iostream>
using namespace std;

class stack
{
	public:
		int top;
		int arr[5];
	
	stack()
	{
		top=-1;
	
	bool isEmpty()
	{
		if(top==-1)
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
		if(top==4)
		{
			return true;
		}
		
		else
		{
			return false;
		}
	}
	
	void push(int val);
	void pop();
    void display();
	
};

void stack :: push(int val)
{
	if(isFull())
	{
		cout<<"Stack is overflow";
	}
	
	else
	{
		top++;
		arr[top]=val;
	}
}


void stack :: pop()
{
	if(isEmpty())
	{
		cout<<"Stack underflow";
	}
	
	else
	{
		int item=arr[top];
		top--;
		
	}
}


void stack :: display()
{
	cout<<"\nYour Stack is as follows: \n";
	for(int i=top;i>=0;i--)
	{
		cout<<"\t";
		cout<<arr[i]<<"\n";
	}
}


int main()
{
	int ch,val,start=1;
	
	stack s1;
	
	while(start==1)
	{
		cout<<"\n1)Push\n2)Pop\n3)isEmpty\n4)isFull\n";
		cout<<"\nEnter your choice: ";
		cin>>ch;
		
		switch(ch)
		{
			case 1:
				cout<<"\nEnter value to be push: ";
				cin>>val;
				s1.push(val);
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
			
			case 4:
			
				if(s1.isFull())
				{
					cout<<"\n\nStack is Overflow";
				}
			    
			    else
			    {
			    	cout<<"\n\nStack is Underflow";
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
