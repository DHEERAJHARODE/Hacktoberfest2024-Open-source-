#include<stdlib.h>
#include <stdio.h>
void create();
void display();
struct node
{
        int info;
        struct node *next;
};
struct node *start=NULL;
int main()
{
        int choice;
        while(1){

                printf("\n 1.Create     \n");
                printf("\n 2.Display    \n");
                printf("\n 3.Exit       \n");
                printf("Enter your choice:\t");
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1:
                                        create();
                                        break;
                        case 2:
                                        display();
                                        break;

                        case 3:
                                        exit(0);
                                        break;

                        default:
                                        printf("\n Wrong Choice:n");
                                        break;
                }
        }
        return 0;
}
void create()
{
        struct node *temp,*ptr;
        temp=(struct node *)malloc(sizeof(struct node));
       /* if(temp==NULL)
        {
                printf("\n Out of Memory Space:\n");
                exit(0);
        }*/
        printf("\nEnter the data value for the node:\t");
        scanf("%d",&temp->info);
        temp->next=NULL;
        if(start==NULL)
        {
                start=temp;
        }
        else
        {
                ptr=start;
                while(ptr->next!=NULL)
                {
                        ptr=ptr->next;
                }
                ptr->next=temp;
        }
}
void display()
{
        struct node *ptr;
       /* if(start==NULL)
        {
                printf("\nList is empty:\n");
                return;
        }
        else
        {
                ptr=start;
                printf("\n The List elements are:\t");
                while(ptr!=NULL)
                {
                        printf("%d ",ptr->info );
                        ptr=ptr->next ;
                }
        }*/
        printf("\n The List elements are:\t");
        for(ptr=start;ptr!=NULL;ptr=ptr->next)
            printf("%d \n",ptr->info );
}
