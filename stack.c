#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*top=NULL;
void push(int num)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=num;
	temp->next=NULL;
	if(top==NULL)
		top=temp;
	else
	{
		temp->next=top;
		top=temp;
	}
}
void pop()
{
	if(top==NULL)
		printf("empty");
	else
	{
		printf("deleteed %d\n",top->data);
		struct node *temp=top;
		top=top->next;
		free(temp);
	}
}
void display()
{
	struct node *p=top;
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
