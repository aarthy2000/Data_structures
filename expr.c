#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
struct node
{
	char data;
	struct node *l;
	struct node *r;
}*root;

void display()
{
	struct node *p=stack[top];
	while(p!=NULL)
	{
		printf("%d->",p->data);
		
	}
}
struct node *stack[10];
int top=-1;
void push(char num)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=num;
	temp->l=NULL;
	temp->r=NULL;
	if(top<10)
		stack[++top]=temp;
//printf("push done");
}
struct node* pop()
{
	struct node *p;
	p=stack[top--];
//	printf("pop done");
	return p;
}

void createnode(char oper)
{

	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=oper;
	temp->l=pop();
	temp->r=pop();
	stack[++top]=temp;
}
void inorder(struct node *p)
{
	if(p==NULL)
		return ;
	else
	{
	inorder(p->l);
	printf("%c ",p->data);
	inorder(p->r);
	}
}
int main()
{
	int i=0;
	char expr[20];
	scanf("%s",expr);
	for(i=0;expr[i]!='\0';i++)
	{
		if(isalnum(expr[i]))
		{
			push(expr[i]);
		}
		else 
		{
			createnode(expr[i]);
		}
		inorder(stack[top]);
	}
}
