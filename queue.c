#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*front=NULL;
void push(int num)
{
	struct node *p=front;
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=num;
	temp->next=NULL;
	if(front==NULL)
		front=temp;
	else
	{
		while(p->next!=NULL)
			p=p->next;
		p->next=temp;
	}
}
void pop()
{
	if(front==NULL)
		printf("empty");
	else
	{
		printf("deleteed %d\n",front->data);
		struct node *temp=front;
		front=front->next;
		free(temp);
	}
}
void display()
{
	struct node *p=front;
	while(p!=NULL)
	{
		printf("%d->",p->data);
		p=p->next;
	}
}
int main()
{
	int ch=1,n;
	while(ch!=0)
	{
		printf("\n1 or 2\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:{
				       scanf("%d",&n);
				       push(n);
				       break;
			       }
			case 2:
			       {
				       pop();
				       break;
			       }
		}
		display();
	}
	return 0;
}
