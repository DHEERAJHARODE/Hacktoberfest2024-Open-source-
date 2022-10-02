#include<iostream>
using namespace std;
#define MAX 50
#include<strings.h>
#include<sstream>
#include<math.h>
#include<bits/stdc++.h>
#include<stack>

class stack
{
	public:
		int top;
		string str[MAX];
	
	stack()
	{
		top=-1;
	}
	
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
		if(top==MAX)
		{
			return true;
		}
		
		else
		{
			return false;
		}
	}
	
    void push(string item)
    {
	    if(isFull())
	    {
		    cout<<"Stack is overflow";
	    }
	
	   else
	   {
		   top++;
		   str[top]=item;
	   }
   }


   string pop()
   {
   	    string a = "";
   	
	   if(isEmpty())
	   {
		    cout<<"Stack underflow";
		    return a;
	   }

	   
		a=str[top];
		top--;
		return a;
	   
   }
	
};


class expression
{
	public:
		string infix;
		string postfix;
		
		stack s; //object for stack class
		
		
	void infix_to_postfix();
	void postfix_to_prefix();
	void eval_postfix();
		
		
	bool isOperator(string s)  
    {  
        if(s == "+" || s == "-" || s == "*" || s == "/" || s == "^"  ) 
        {
            return true;    
	    }
	    
	    else
	    {
            return false;
		}
    }  
  

    int precedence(string op)  
    {  
        if(op == "+" || op == "-")  
		{
			return 1;
		}
		
        else if (op == "*" || op == "/") 
		{
		    return 2;
	    }

        else if(op == "^")  
	    {
	   	    return 3;
	    }                                
        
        else
        {
        	return 0;
		}
    }
    
  
    bool isOperand(string s)  
    {  
        if(s >= "A" && s <= "Z")
		{
			return true;
			
		}
		
        else if(s >= "a" && s <= "z")
		{
			return true;
		}   
 
        else if(s >= "0" && s <= "9") 
	    {
	   	    return true;
	    } 
		
		else
		{
			return false;
		} 
    }
 
};

void expression :: infix_to_postfix()
{
	cout<<"\nEnter infix expression: ";
	cin>>infix;
	
	for(int i=0;i<infix.length();i++)
	{
		if(isOperand(string(1,infix[i])))
		{
			postfix=postfix+infix[i];
			
		}
		
		else if(infix[i]=='(')
		{
			s.push("(");
		}
		
		else if(infix[i] == ')')
		{
			while(s.top!=-1 && s.str[s.top]!= "(")
			{
				string t= s.str[s.top];
				s.pop();
				
				postfix = postfix+t;
			}
			
			if(s.str[s.top] == "(" )
			{
				s.pop();
			}
		}
		
		else
		{
			while(s.top!=-1 && (precedence(string(1,infix[i])) <= precedence(s.str[s.top])))
			{
				string t= s.str[s.top];
				s.pop();
				
				postfix = postfix+t;
			}
			
			s.push(string(1,infix[i]));
		}
	}
	
	while(s.top!=-1)
    {
		string t= s.str[s.top];
		s.pop();
		postfix = postfix+t;		
		
	}
	
	cout<<"\nPostfix expression is: "<<postfix;
}


void expression :: postfix_to_prefix()
{
	string post;
	string pref;
	
	cout<<"\nEnter postfix expression: ";
	cin>>post;
	
	for(int i=0;i<post.length();i++)
	{
		if(isOperator(string(1,post[i])))
		{
			
			string op1 = s.pop();
            string op2 = s.pop();
			
			string t = post[i]+op2+op1;
			s.push(t);
		}
		
		else
		{
			s.push(string(1,post[i]));
		}
	
	}
	
	pref=s.pop();

	cout<<"\nPrefix expression is: "<<pref;
}


void expression :: eval_postfix()
{
	int ans,t1,t2;
	string s1,s2;
	string post1;
	
	cout<<"\nEnter postfix Expression: ";
	cin>>post1;
	
	for(int i=0;i<post1.length();i++)
	{
		if(isOperator(string(1,post1[i])))
		{
			
			s2=s.pop();
			s1=s.pop();
			
			stringstream change_2(s2);
			stringstream change_1(s1);
			
			change_2 >> t2;
			change_1 >> t1;
			
			if(post1[i] == '+')
			{
				ans = t1+t2;
			}
			
			if(post1[i] == '-')
			{
				ans = t1-t2;
			}
			
			if(post1[i] == '*')
			{
				ans = t1*t2;
			}
			
			if(post1[i] == '/')
			{
				ans = t1/t2;
			}
			
			if(post1[i] == '^')
			{
				ans = pow(t1,t2);
			}
			
			ostringstream ans_1;
			ans_1 << ans;
			
			string ans_2 = ans_1.str();
			s.push(ans_2);
		}
		
		else
		{
			if(isdigit(post1[i]))
			{
				s.push(string(1,post1[i]));
			}
		}
	}
	
	string result = s.pop();
	
	cout<<"Postfix answer is: "<<result;
}



int main()
{
	int ch,val;
	char start='y';
	
	stack s1;
	expression exp;
	
	
	while(start=='y')
	{
		cout<<"\n1)Infix to postfix\n2)Postfix to prefix\n3)Evaluate postfix\n";
		cout<<"\nEnter your choice: ";
		cin>>ch;
		
		switch(ch)
		{
			case 1:
				
				exp.infix_to_postfix();
			
			    break;
			    
			case 2:
				exp.postfix_to_prefix();
				
				break;
			
			case 3:
				exp.eval_postfix();
			
				break;
			
			default:
			    cout<<"\nIncorrect choice !!";	
		}
		
		cout<<"\n\nDo you want to continue (y/n): ";
		cin>>start;
	}
	
	cout<<"\nThankyou !!!";
	
	return 0;
}
