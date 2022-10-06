#include<iostream>
#include<string>

#define MAX 20

using namespace std;

class stack
{
    char data[MAX];
    int top = -1;
public:
    void push(char oprtr)
    {
        if(top == MAX-1)
        {
            cout<<"\nStack is full!!\n";
        }
        else
        {
            top++;
            data[top]=oprtr;
        }

    }

    char pop()
    {
        char oprtr;
        if(top == -1)
        {
            cout<<"\nStack is empty!!\n";
            return '\0';
        }
        else
        {
            oprtr = data[top];
            data[top]='\0';
            top--;
            return oprtr;
        }
    }

    int priority( char oprtr)
    {
        if(oprtr == '+' || oprtr == '-')
            {
                return 1;
            }

        if(oprtr == '*' || oprtr == '/')
            {
                return 2;
            }

        if(oprtr == '$')
            {
                return 3;
            }

        return 0;
    }

    string convert(string infix)
    {
        int i=0;
        int j;
        string postfix = "";
        while(infix[i]!='\0')
        {
            if(infix[i] >= 'a'&&infix[i] <= 'z' || infix[i] >= 'A' && infix[i]<='Z')
            {
                postfix += infix[i];
                i++;
            }
            else if(infix[i] == '(')
            {
                push(infix[i]);
                i++;
            }
            else if(infix[i] == ')')
            {
                while(data[top] != '(')
                {
                    postfix += pop();
                }
                pop();
                i++;
            }
            else
            {
                if(top == -1)
                {
                    push(infix[i]);
                    i++;
                }

                else if(priority(infix[i]) <= priority(data[top]))
                {
                    char tmp;
                    if(infix[i] == '$' && data[top] == '$')
                    {
                        push(infix[i]);
                        i++;
                    }
                    else
                    {
                        postfix += pop();

                        while(priority(infix[i]) == priority(data[top]))
                        {
                            tmp = data[top];
                            postfix += pop();
                            if(top < 0)
                            {
                                break;
                            }
                        }
                        if(tmp = '$' && data[top] == '$')
                        {
                            postfix += pop();
                        }
                        push(infix[i]);
                        i++;
                    }
                }

                else if(priority(infix[i]) > priority(data[top]))
                {
                    push(infix[i]);
                    i++;
                }
            }
        }
        while(top != -1)
        {
            postfix += pop();
        }
        return postfix;
    }
};

int main()
{
    int trash;
    stack stack1;
    string infix, postfix;
    cout<<"\nEnter the infix expression; ";
    cin>>infix;
    postfix = stack1.convert(infix);
    cout<<"\n The corresponding postfix expression is: "<<postfix<<endl;
    cin>>trash;
    return 0;
}
