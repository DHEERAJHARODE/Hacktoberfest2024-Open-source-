#include <iostream>
#define size 100
using namespace std;
class stack
{
public:
    int top;
    int count = 0;
    char str[size];
    stack()
    {
        top = -1;
    }
    bool empty()
    {
        if (top == -1)
        {
            return 1;
        }
        else
            return 0;
    }
    bool full()
    {
        if (top == size - 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    void push(char c)
    {
        if (full())
        {
            cout << "Stack is full" << endl;
        }
        else
        {
            top++;
            str[top] = c;
        }
        count++;
    }
    void pop()
    {
        if (empty())
        {
        }
        else
        {
            top = top - 1;
        }
        count--;
    }
};
int main()
{
    stack s1, s2, s3;
    char exp[100], ch;
    int i = 0;
    cout << "enter expression:";
    cin >> exp;
    if ((exp[0] == ')') || (exp[0] == '}') || (exp[0] == ']'))
    {
        cout << "invalid expression" << endl;
    }
    else
    {
        while (exp[i] != '\0')
        {
            ch = exp[i];
            switch (ch)
            {
            case '(':
                s1.push(ch);
                break;
            case '{':
                s2.push(ch);
                break;
            case '[':
                s3.push(ch);
                break;
            case ')':
                s1.pop();
                break;
            case '}':
                s2.pop();
                break;
            case ']':
                s3.pop();
                break;
            }
            i++;
        }
    }
    if (s1.empty() && s1.count == 0 && s2.count == 0 && s3.count == 0 && s2.empty() && s3.empty())
    {
        cout << "expression is well parenthesized";
    }
    else
    {
        cout << "expression is not well parenthesized";
    }
    return 0;
}
