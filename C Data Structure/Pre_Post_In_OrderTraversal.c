#include <stdio.h>
#include <stdlib.h>

struct node
{
     int data;
     struct node* left;
     struct node* right;
};
void Enqueue(struct node **a,int *r,struct node *new_node)
{
     a[(*r)] = new_node;
     (*r)++;

}
struct node *Dequeue(struct node **a,int *f)
{
     (*f)++;
     return a[(*f)-1];
}
 
struct node* newNode(int data)
{
     struct node* node = (struct node*)malloc(sizeof(struct node));
     node->data = data;
     node->left = NULL;
     node->right = NULL;
 
     return(node);
}
 
void printPostorder(struct node* node)
{
     if (node == NULL)
        return;
     printPostorder(node->left);
     printPostorder(node->right);
     printf("%d ", node->data);
}
 
void printInorder(struct node* node)
{
     if (node == NULL)
          return;
     printInorder(node->left);
     printf("%d ", node->data);  
     printInorder(node->right);
}
 

void printPreorder(struct node* node)
{
     if (node == NULL)
          return;
     printf("%d ", node->data);  
     printPreorder(node->left);  
     printPreorder(node->right);
}  

void printLevelorder(struct node* node,int n)
{
     struct node *a[n];
     struct node* temp;
     int rear=0,front=0;
     temp = node;
     while(temp)
     {
          printf("%d ",temp->data );
          if(temp->left)
               Enqueue(a,&rear,temp->left);
          if(temp->right)
               Enqueue(a,&rear,temp->right);
          temp = Dequeue(a,&front);
     }
} 

int height(struct node* node)
{
    if (node==NULL)
        return 0;
    else
    {
          int lheight = height(node->left);
          int rheight = height(node->right);
          if (lheight > rheight)
               return(lheight+1);
          else 
               return(rheight+1);
    }
} 

int main()
{
     struct node *root  = newNode(1);
     root->left = newNode(2);
     root->right = newNode(3);
     (root->left)->left = newNode(4);
     (root->left)->right = newNode(5); 
 
     printf("Preorder traversal of binary tree is \n");
     printPreorder(root);
 
     printf("\nInorder traversal of binary tree is \n");
     printInorder(root);  
 
     printf("\nPostorder traversal of binary tree is \n");
     printPostorder(root);

     printf("\nLevelorder traversal of binary tree is \n");
     printLevelorder(root,5);

     printf("\nHeight of binary tree is \n");
     int h = height(root);
     printf("%d", h);
 

     printf("\n");
     return 0;
}