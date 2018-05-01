//CIRCULAR LINKED LIST
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*head=NULL;
void beg(int num)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=num;
	temp->next=NULL;
	struct node *p=head;
	if(head==NULL)
	{
		head=temp;
		head->next=head;
	}
	else
	{
		while(p->next!=head)
			p=p->next;
		temp->next=head;
		head=temp;
		p->next=head;
	}
}
void end(int num)
{
//	printf("heyyyyyyyyyyyyyyyyyy");
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=num;
	struct node *p=head;
	while(p->next!=head)
		p=p->next;
	p->next=temp;
	temp->next=head;
}
void pos(int num,int key)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data=num;
	temp->next=NULL;
	struct node *p=head;
	while((p->next!=head)&&(p->data!=key))
	{

		p=p->next;
	}
	temp->next=p->next;
	p->next=temp;
}
void dend()
{
	struct node *p=head;
	struct node *q=head;
	while(p->next!=head)
	{
		q=p;
		p=p->next;
	}
	printf(" q->data is %d deleted %d\n",q->data,p->data);
	q->next=head;
	free(p);
}
/*void dbeg()
{
	struct node *temp=head;
	
	head=head->next;
	printf("delteed %d\n",temp->data);
	free(temp);
}*/
void dbeg()
{
   if(head == NULL)
      printf("List is Empty!!! Deletion not possible!!!");
   else
   {
      struct node *temp = head;
	struct node *p=head;
      if(temp -> next == head)
      {
         head = NULL;
         free(temp);
      }
      else{
	while(p->next!=head)
	p=p->next;

         head = head -> next;
		p->next=head;
         free(temp);
      }
      printf("\nDeletion success!!!");
   }
}
void dpos(int key)
{

	struct node *temp=(struct node *)malloc(sizeof(struct node));
	struct node *p,*q;
	p=head;
	q=head;
	while((p->next!=head)&&(p->data!=key))
	{
		q=p;
		p=p->next;
	}
	q->next=p->next;
	printf("deleted %d\n",p->data);
	free(p);
}
void display()
{
	struct node *p=head;
	while(p->next!=head)
	{
//		p=p->next;
		printf("%d-> ",p->data);
		p=p->next;
	}
	printf("%d",p->data);
}

/*void display()
{
   if(head == NULL)
      printf("\nList is Empty!!!");
   else
   {
       struct node *temp = head;
      printf("\nList elements are: \n");
      while(temp -> next != head)
      {
         printf("%d ---> ",temp -> data);
	temp=temp->next;
      }
      printf("%d ---> %d", temp -> data, head -> data);
   }
}*/
int main()
{
	int ch,num,key;

	ch = 1;



	while (ch!=0)

	{
	//	display();
		

		printf("\n---------------------------------\n");

		printf("\nOperations on singly linked list\n");

		printf("\n---------------------------------\n");

		printf("\n1.Insert node at first");

		printf("\n2.Insert node at last");

		printf("\n3.Insert node at position");



		printf("\n4.Delete Node from any Position\n 5.beg..\n 6 end");





		printf("\n8.Display List from Beginning to end");


		printf("\n0.Exit\n");

		printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

		printf("\nEnter your choice");

		scanf("%d", &ch);



		switch (ch)

		{

			case 1: 
			{
				printf("\n...Inserting node at first...\n");
				scanf("%d",&num);
				beg(num);

				break;
			}
			case 2: 

			{	printf("\n...Inserting node at last...\n");
				scanf("%d",&num);
				end(num);

				break;
			}
			case 3: 
			{
				printf("\n...Inserting node at position...\n");
				scanf("%d%d",&num,&key);

				pos(num,key);

				break;
			}


			case 4: 

			{	printf("\n...Deleting Node from any Position...\n");
				scanf("%d",&key);

				dpos(key);

				break;
			}
			case 5:
			{
				printf("whyam i here?");
				dbeg();
			
				break;
			}
			case 6:
			{
				printf("is that me??");	dend();
				break;}

		}
	display();
}
		return 0;

	}	

