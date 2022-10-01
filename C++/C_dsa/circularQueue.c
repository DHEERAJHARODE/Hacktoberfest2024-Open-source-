#include<stdio.h>
#include<stdlib.h>

struct queue{
    int front,rear,size;
    unsigned capacity;
    int* array;
};


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

// void isEmpty(struct stack *s){
//     if(s->top == -1){
//         printf("Stack is empty\n");
//     }
//     else{
//         printf("Stack is not empty\n");
//     }
// }

// void isFull(struct stack *s){
//     if(s->top == s->size - 1){
//         printf("Stack is full\n");
//     }
//     else{
//         printf("Stack is not full\n");
//     }
// }

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

struct queue* create(unsigned capacity){
    struct queue *q = (struct queue*)malloc(sizeof(struct queue));
    q->capacity = capacity;
    q->front = 0;
    q->rear = 0;
    q->size = 0;
    q->array = (int*)malloc(q->capacity*sizeof(int));
    return q;
}

int isFull(struct queue* q){
    return ((q->rear+1)%(q->capacity) == q->front);
}

int isEmpty(struct queue* q){
    return (q->size == 0);
}

void enqueue(struct queue *q,int data){
    if(isFull(q)){
        printf("Queue is full\n");
    }
    else{
        q->size++;
        q->rear = (q->rear+1)%(q->capacity);
        q->array[q->rear] = data;
    }
}

void denqueue(struct queue *q){
    if(isEmpty(q)){
        printf("Queue is empty\n");
    }
    else{
        q->size--;
        q->front = (q->front+1)%(q->capacity);
    }
}

void display(struct queue *q){
    if(q->size == 0){
        printf("Queue is empty\n");
    }
    else{
        int i;
        for(i=q->front+1;i<=q->rear;i++){
            printf("%d ",q->array[i]);
        }
        printf("\n");
    } 
}

void rear(struct queue *q){
    if(isEmpty(q)){
        printf("Queue is empty\n");
    }
    else{
        printf("Rear element is %d\n",q->array[q->rear]);
    }
}

void front(struct queue *q){
    if(isEmpty(q)){
        printf("Queue is empty\n");
    }
    else{
        printf("Front element is %d\n",q->array[q->front+1]);
    }
}

int findmaxQueue(struct queue *q){
    int max = INT_MIN;
   if(q->size == 0){
        printf("Queue is empty\n");
    }
    else{
        int i;
        for(i=q->front+1;i<=q->rear;i++){
            if(q->array[i]>max){
                max = q->array[i];
            }
        }
        return max;
    } 
}

void reverseQueue(struct queue *q,int k){
    struct stack *st = createStack(100);
    for(int i=q->front+1;i<=q->rear && i<=k;i++){
        push(st,q->array[i]);
    }
    printf("Reversing the queue using a stack: ");
    for(int i=0;i<k;i++){
        printf("%d ",peek(st));
        pop(st);
    }
}

int main(){
    struct queue *q = create(10);
    for(int i =0 ;i<10;i++){
        enqueue(q,i);
    }
    denqueue(q);
    printf("maximum element in the queue is: %d \n",findmaxQueue(q));
    display(q);
    front(q);
    rear(q);
    reverseQueue(q,4``);
    return 0;
}