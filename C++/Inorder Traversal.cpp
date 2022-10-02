#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left, *right;
};

struct node* create(int data){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->left=NULL; 
    temp->right=NULL;
    return temp;
}
 
void swaprequired(struct node **a, struct node **b){
    struct node * temp = *a;
    *a=*b;
    *b= temp;
}


void inorder(struct node *root){
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
 
int main(){
    struct node *root = create(7);
    root->left = create(10);
    root->right = create(60);
    root->left->left = create(290);
    root->left->right = create(19);
    root->right->right = create(50);
    root->right->left = create(55);

 
    printf("Original Tree :");
    inorder(root);
 
    swaprequired(&root->left,&root->right);
 
    printf("\nAfter swapping :");
    inorder(root);
    return 0;
}
