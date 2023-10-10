#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define MAX_SIZE 100

typedef struct stack{
    int top;
    char a[MAX_SIZE];
}stack;

bool isEmpty(stack *s){
    if(s->top==-1){
        return true;
    }
    else return false;
}

void push(stack *s, char x){
    s->top+=1;
    s->a[s->top]=x;
}

char pop(stack *s){
    return s->a[s->top--];
}

bool isOperator(char x){
    if(x=='+' || x=='-' || x=='*' || x=='/'){
        return true;
    }
    else return false;
}

bool isOperand(char x){
    if((x>='0' && x<='9') || (x>='a' && x<='z') || (x>='A' && x<='Z')){
        return true;
    }
    else return false;
}

char* reverse(char exp[]){
    int len = strlen(exp);
    char* reversed = (char*)malloc((len + 1) * sizeof(char));
    for(int i = 0; i < len; i++){
        reversed[i] = exp[len - i - 1];
    }
    reversed[len] = '\0';
    return reversed;
}

int precedence(char x){
    if(x=='^') return 3;
    else if(x=='*' || x=='/') return 2;
    else if(x=='+' || x=='-') return 1;
    else return -1;
}

char* infixToPrefix(stack *s, char inExp[]){
    char a[MAX_SIZE];
    int index=-1;
    char *exp=reverse(inExp);
    for(int i=0; i<strlen(exp); i++){
        if(isOperand(exp[i])){
            a[++index]=exp[i];
        }
        else if(isOperator(exp[i])){
            if(!isEmpty(s) && precedence(s->a[s->top])<precedence(exp[i])){
                push(s, exp[i]);
            }
            else if(!isEmpty(s) && precedence(s->a[s->top])>precedence(exp[i])){
                while(!isEmpty(s) && precedence(s->a[s->top])>precedence(exp[i])){
                    a[++index]=pop(s);;
                }
                push(s, exp[i]);
            }
            else {
                push(s, exp[i]);
            }
        }
    }
    while(!isEmpty(s)){
        a[++index]=pop(s);
    }
    a[++index]='\0';
    char *result = reverse(a);
    return result;
}

int main(){
    stack *s = (stack*)malloc(sizeof(stack));
    s->top=-1;
    char exp[MAX_SIZE];
    printf("Enter infix expression: "); 
    gets(exp);
    printf("Infix converted to prefix: ");
    char* result = infixToPrefix(s, exp);
    printf("%s", result);
    free(s);
    free(result);
    return 0;
}