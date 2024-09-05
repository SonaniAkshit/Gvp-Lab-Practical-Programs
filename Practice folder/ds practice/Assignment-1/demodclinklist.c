#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
	struct node *prev;
}*head,*curr;
void insert();
void display();
void main()
{
	int ch;
	
	while(1)
	{
		printf("\n1)Insert.");
		printf("\n2)Display.");
		printf("\n3)Exit.");
		
		printf("\nEnter any choice:");
		scanf("%d",&ch);
				
		switch(ch)
		{
			case 1: insert(); break;
			case 2: display(); break;
			case 3: exit(0);	
		}	
	}
}
//void insert()
//{
//	struct node *new1;
//	new1=(struct node*)malloc(sizeof(struct node));
//	
//	printf("\nEnter any value:");
//	scanf("%d",&new1->data);
//	
//	if(head==0)
//	{
//		head=curr=new1;
//		new1->prev=curr;
//		new1->next=head;
//		printf("\ninsert in first..");
//	}
//	else
//	{
//		new1->next=head;
//		head->prev=new1;
//		new1->prev=curr;
//		curr->next=new1;
//		head=new1;
//		printf("\ninsert in last..");
//	}
//}

void insert() 
{
    struct node *new1, *temp;
    new1 = (struct node *)malloc(sizeof(struct node));

    printf("\nEnter any value: ");
    scanf("%d", &new1->data);

    if (head == NULL || new1->data <= head->data)
	{
        new1->next = head;
        if (head != NULL) 
		{
            head->prev = new1;
        }
        head = curr = new1;
        new1->prev = curr;
        printf("\ninsert on first...\n");
    } 
	else 
	{
        temp = head;
        while (temp->next != NULL && temp->next->data < new1->data) 
		{
            temp = temp->next;
        }
        new1->next = temp->next;
        if (temp->next != NULL) 
		{
            temp->next->prev = new1;
        }
        temp->next = new1;
        new1->prev = temp;
        printf("\ninsert in sort order...\n");
    }
}

void display()
{
	struct node *temp;
	temp=head;
	
	if(head==0)
	{
		printf("node is empty..");
	}
	else
	{
		
		do
		{
			printf("%d->",temp->data);
			temp=temp->next;
		}
		while(temp!=curr);
	}
}
