#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 100

typedef struct stack{
    char a[MAX_SIZE];
    int top;
} stack;

void push(stack *s, int x){
    s->top+=1;
    s->a[s->top]=x;
}

int pop(stack *s){
    s->top-=1;
    return s->a[s->top+1];
}

int prefixEval(char exp[MAX_SIZE], stack *s){
    for(int i=0; i<strlen(exp); i++){
        if(exp[i]>='0' && exp[i]<='9'){
            push(s, exp[i]-'0');
        }
        else{
            int p = pop(s);
            int q = pop(s);
            if(exp[i]=='+') push(s, p+q);
            else if(exp[i]=='-') push(s, p-q);
            else if(exp[i]=='*') push(s, p*q);
            else if(exp[i]=='/') push(s, p/q);
        }
    }
    return s->a[s->top];
}

int main(){
    stack *s = malloc(sizeof(stack));
    s->top=-1;
    char exp[MAX_SIZE];
    printf("Enter prefix expression: ");
    scanf("%s", exp);
    for(int i=0; i<strlen(exp)/2; i++){
        char temp = exp[i];
        exp[i]=exp[strlen(exp)-i-1];
        exp[strlen(exp)-i-1]=temp;
    }
    printf("Result of the expression: %d",  prefixEval(exp, s));
    free(s);
    return 0;
}