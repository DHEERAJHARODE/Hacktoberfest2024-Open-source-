#include<stdio.h>
#include<stdlib.h>


struct stack{
    int size;
    int top;
    int *arr;
};

struct stack* createStack(int size){
    struct stack *s = (struct stack*)malloc(sizeof(struct stack));
    s->size = size;
    s->top = -1;
    s->arr = (int *)malloc(s->size * (sizeof(int)));
    return s;
}

void isEmpty(struct stack *s){
    if(s->top == -1){
        printf("Stack is empty\n");
    }
    else{
        printf("Stack is not empty\n");
    }
}

void isFull(struct stack *s){
    if(s->top == s->size - 1){
        printf("Stack is full\n");
    }
    else{
        printf("Stack is not full\n");
    }
}

void push(struct stack *s,int data){
    if(s->top == s->size-1){
        printf("Stack overflow\n");
    }
    else{
        s->top++;
        s->arr[s->top]=data;
    }
}

void displayTop(struct stack *s){
    if(s->top == -1){
        printf("Stack is empty\n");
    }
    else{
        printf("Top element is %d\n",s->arr[s->top]);
    }
}

int peek(struct stack *s){
    if(s->top == -1){
        printf("Stack is empty\n");
    }
    else{
        return s->arr[s->top];
    }
}

void pop(struct stack *s){
    if(s->top == -1){
        printf("Stack underflow\n");
    }
    else{
        // printf("Popped element is %d\n",s->arr[s->top]);
        s->top--;
    }
}


int main(){
    struct stack *s = createStack(100);
    isEmpty(s);
    push(s,10);
    push(s,20);
    pop(s);
    displayTop(s);
    isFull(s);
    return 0;
}