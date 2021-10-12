#include<stdio.h>

int max=10,num,top=-1,data;
int stack[10];

int main(){
    int x;
    do{
    printf("\t1:Add Number to Stack \n\t2:Delete From Stack \n\t3:Print \n\t4:Exit \n");
    scanf("%d",&x);
    switch(x){
    case 1:
        printf("Enter Number to Add to the stack:");
        scanf("%d",&num);
        push(num);
        break;
    case 2:
        pop();
        break;
    case 3:
        display();
        break;
    case 4:
        break;
    }
    }while(x!=4);
}
int push(int data){
    if(isfull()== 1)
        printf("Stack is full");
    else
        top=top+1;
        stack[top]=data;

}
int pop(){
    printf("\tPOP Function \n");
    if(isempty() == 1)
        printf("Stack is Empty");
    else
        //return stack[top];
        printf("Number %d is Deleted",stack[top]);
        top=top-1;
}
int isfull(){
    if(top==(max-1)){
        return 1;
    }else{
    return 0;
    }
}
int isempty(){
    if(top==-1){
        return 1;
    }else{
    return 0;
    }
}
int display(){
    int i;
    if(isempty()!= 1){
            printf("Numbers in the stack");
        for(i=0;i<=top;i++){
            printf("%d \n",stack[top-i]);
        }

}
}
