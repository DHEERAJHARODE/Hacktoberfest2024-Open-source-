#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*head;

struct node* createList(int n){
    struct node *newnode,*temp;
    int data;
    scanf("%d",data);
    head->data = data;
    head->next = NULL;
    newnode = head;
    for(int i=2;i<=n;i++){
        temp = (struct node*)malloc(sizeof(struct node));
        scanf("%d",temp->data);
        temp->next = NULL;
        newnode->next = temp;
    }
}

void display(struct node* n){
    while(n != NULL){
        printf("%d ",n->data);
        n=n->next;
    }
}

int main(){
    head = createList(50);
    display(head);
    return 0;
}