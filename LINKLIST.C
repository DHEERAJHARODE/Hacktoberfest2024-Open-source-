/* Program of single linked list*/
# include <stdio.h>
# include <malloc.h>

struct node
{
	int info;
	struct node *link;
}*start;

main()
{
	int choice,n,m,position,i;
	start=NULL;
	while(1)
	{
		printf("1.Create List\n");
		printf("2.Add at begining\n");
		printf("3.Add after \n");
		printf("4.Delete\n");
		printf("5.Display\n");
		printf("6.Count\n");
		printf("7.Reverse\n");
		printf("8.Search\n");
		printf("9.Quit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
		 case 1:
			printf("How many nodes you want : ");
			scanf("%d",&n);
			for(i=0;i<n;i++)
			{
				printf("Enter the element : ");
				scanf("%d",&m);
				create_list(m);
			}
			break;
		 case 2:
			printf("Enter the element : ");
			scanf("%d",&m);
			addatbeg(m);
			break;
		 case 3:
			printf("Enter the element : ");
			scanf("%d",&m);
			printf("Enter the position after which this element is inserted : ");
			scanf("%d",&position);
			addafter(m,position);
			break;
		 case 4:
			if(start==NULL)
			{
				printf("List is empty\n");
				continue;
			}
			printf("Enter the element for deletion : ");
			scanf("%d",&m);
			del(m);
			break;
		 case 5:
			display();
			break;
		 case 6:
			count();
			break;
		 case 7:
			rev();
			break;
		 case 8:
			printf("Enter the element to be searched : ");
			scanf("%d",&m);
			search(m);
			break;
		 case 9:
			exit();
		 default:
			printf("Wrong choice\n");
		}/*End of switch */
	}/*End of while */
}/*End of main()*/

create_list(int data)
{
	struct node *q,*tmp;
	tmp= malloc(sizeof(struct node));
	tmp->info=data;
	tmp->link=NULL;

	if(start==NULL) /*If list is empty */
		start=tmp;
	else
	{       /*Element inserted at the end */
		q=start;
		while(q->link!=NULL)
			q=q->link;
		q->link=tmp;
	}
}/*End of create_list()*/

addatbeg(int data)
{
	struct node *tmp;
	tmp=malloc(sizeof(struct node));
	tmp->info=data;
	tmp->link=start;
	start=tmp;
}/*End of addatbeg()*/

addafter(int data,int pos)
{
	struct node *tmp,*q;
	int i;
	q=start;
	for(i=0;i<pos-1;i++)
	{
		q=q->link;
		if(q==NULL)
		{
			printf("There are less than %d elements",pos);
			return;
		}
	}/*End of for*/

	tmp=malloc(sizeof(struct node) );
	tmp->link=q->link;
	tmp->info=data;
	q->link=tmp;
}/*End of addafter()*/

del(int data)
{
	struct node *tmp,*q;
	if(start->info == data)
	{
		tmp=start;
		start=start->link;  /*First element deleted*/
		free(tmp);
		return;
	}
	q=start;
	while(q->link->link != NULL)
	{
		if(q->link->info==data)     /*Element deleted in between*/
		{
			tmp=q->link;
			q->link=tmp->link;
			free(tmp);
			return;
		}
		q=q->link;
	}/*End of while */
	if(q->link->info==data)    /*Last element deleted*/
	{
		tmp=q->link;
		free(tmp);
		q->link=NULL;
		return;
	}
	printf("Element %d not found\n",data);
}/*End of del()*/

display()
{
	struct node *q;
	if(start == NULL)
	{
		printf("List is empty\n");
		return;
	}
	q=start;
	printf("List is :\n");
	while(q!=NULL)
	{
		printf("%d ", q->info);
		q=q->link;
	}
	printf("\n");
}/*End of display() */

count()
{
	struct node *q=start;
	int cnt=0;
	while(q!=NULL)
	{
		q=q->link;
		cnt++;
	}
	printf("Number of elements are %d\n",cnt);
}/*End of count() */

rev()
{
	struct node *p1,*p2,*p3;
	if(start->link==NULL)    /*only one element*/
		return;
	p1=start;
	p2=p1->link;
	p3=p2->link;
	p1->link=NULL;
	p2->link=p1;
	while(p3!=NULL)
	{
		p1=p2;
		p2=p3;
		p3=p3->link;
		p2->link=p1;
	}
	start=p2;
}/*End of rev()*/

search(int data)
{
	struct node *ptr = start;
	int pos = 1;
	while(ptr!=NULL)
	{
		if(ptr->info==data)
		{
			printf("Item %d found at position %d\n",data,pos);
			return;
		}
		ptr = ptr->link;
		pos++;
	}
	if(ptr == NULL)
		printf("Item %d not found in list\n",data);
}/*End of search()*/