#include<stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};
void insert_node(struct node *, int);
void display_node(struct node *);
void delete_node(struct node * ,int);

void main()
{
	int ch,data;
	struct node *head= NULL;
	
	printf("\n=====MENU=====\n");	
	printf("\n1.Insert First.");	
	printf("\n2.Display.");	
	printf("\n3.Delete First.");	
	printf("\n3.Exit.");	
	printf("\n==============\n");	
	printf("Enter Your Choice:");
	scanf("%d",&ch);
	
	switch(ch)
	{
		case 1: 
			insert_node(head,data);
			main();
			break;
			
		case 2: 
			display_node(head);
			main();
			break;
			
		case 3:
			delete_node(head,data); 
			main();
			break;
			
		case 4: 
				exit(0);
	}
getch();
}
void insert_node(struct node *head ,int data)
{
	struct node *new;
	new=(struct node*)malloc(sizeof(struct node));
	printf("Enter Any Element:");
	scanf("%d",&new->data);
	if(new==NULL)
	{
		printf("Memory allocation failed\n");
        return;
	}
	new->data=data;
	new->next=head;
	head=new;
	printf("\nElement Inserted in Node...%d",new->data);
}
void display_node(struct node *head)
{
	struct node *temp;
	temp=head;
	printf("\n");
	
	if(head!=NULL)
	{
		printf("%d",temp->data);
		temp=temp->next;
	}
}
/*void display_node(struct node *head) 
{
    struct node *temp = head;
    printf("\n");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}*/

void delete_node(struct node *head ,int data)
{
	printf("\ndelete okay");	
}
