#include<iostream>
#include<cstdio>
#include<cmath>
#include<stack>
using namespace std;
int isOperand(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (isdigit(ch));
}

int checkPrecedence(char ch) {
    switch (ch) {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    }
    return -1;
}

int infixToPostfix(char exp[], char output[]) {
    int i = 0, k = 0;
    stack < char > st;
    while (exp[i]) {
        if (isOperand(exp[i]))
            output[k++] = exp[i];
        else if (exp[i] == '(')
            st.push(exp[i]);
        else if (exp[i] == ')') {
            while (!st.empty() && st.top() != '(') {
                output[k++] = st.top();
                st.pop();
            }
            if (!st.empty() && st.top() != '(')
                return -1;
            else
                st.pop();
        } else {
            while (!st.empty() && checkPrecedence(exp[i]) <= checkPrecedence(st.top())) {
                output[k++] = st.top();
                st.pop();
            }
            st.push(exp[i]);
        }
        i++;
    }

    while (!st.empty()) {
        output[k++] = st.top();
        st.pop();
    }

    output[k++] = '\0';
}

int main() {
    char exp[] = "6/(3^2)-8";
    char output[20];
    infixToPostfix(exp, output);
    cout << "Given infix expression is : " << exp << endl;
    cout << "Equivalent postfix expression is : " << output << endl;
    return 0;
}
