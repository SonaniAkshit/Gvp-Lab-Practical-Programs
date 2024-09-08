#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
}*head;

void insert();
void display();
void delete();
void modify();

void main() 
{
    int ch;

    head = NULL;

    while (1) 
	{
        printf("\n1)Insert.");
        printf("\n2)Display.");
		printf("\n3)Delete.");
		printf("\n4)Modify.");
        printf("\n5)Exit.");

        printf("\nEnter any choice: ");
        scanf("%d", &ch);

        switch (ch) 
		{
            case 1: insert(); break;
            case 2: display(); break;
            case 3: delete(); break;
            case 4: modify(); break;
			case 5: exit(0);
        }
    }
}

void insert()
{
    struct node *new1, *curr;
    new1 = (struct node *)malloc(sizeof(struct node));

    printf("\nEnter any value: ");
    scanf("%d", &new1->data);

    if (head == NULL) 
	{
        head = new1;
        new1->next = head;
        new1->prev = head;
        printf("\nInserted at the beginning.\n");
    } 
	else if (new1->data <= head->data) 
	{
        new1->next = head;
        new1->prev = head->prev;
        head->prev->next = new1;
        head->prev = new1;
        head = new1;
        printf("\nInsert First.\n");
    } 
	else 
	{
        curr = head;
        while (curr->next != head && curr->next->data < new1->data) 
		{
            curr = curr->next;
        }
        new1->next = curr->next;
        new1->prev = curr;
        curr->next->prev = new1;
        curr->next = new1;
        printf("\nInsert sorted.\n");
    }
}

void display() 
{
    struct node *curr;
    curr = head;

    if (head == NULL) 
	{
        printf("Node is empty.\n");
    } 
	else 
	{
        do
		{
            printf("%d->", curr->data);
            curr = curr->next;
        }
		while(curr != head);
    }
}

void delete() 
{
    int ele;
    struct node *curr;

    printf("\nEnter the value to be deleted: ");
    scanf("%d", &ele);

    if (head == NULL)
	{
        printf("\nList is empty.\n");
        return;
    }

    if (head->next == head) 
	{
        if (head->data == ele) 
		{
            free(head);
            head = NULL;
            printf("\nDeleted from the list.\n");
            return;
        }
        else 
		{
            printf("\nValue not found in the list.\n");
            return;
        }
    }

    if (head->data == ele) 
	{
        curr = head;
        head->prev->next = head->next;
        head->next->prev = head->prev;
        head = head->next;
        free(curr);
        printf("\nDeleted from the beginning.\n");
        return;
    }

    curr = head;
    while (curr->next != head && curr->next->data != ele) 
	{
        curr = curr->next;
    }

    if (curr->next == head) 
	{
        printf("\nValue not found in the list.\n");
        return;
    }

    struct node *nodeToDelete = curr->next;
    curr->next = nodeToDelete->next;
    nodeToDelete->next->prev = curr;
    free(nodeToDelete);
    printf("\nDeleted from the list.\n");
}
void modify() 
{
    int oldVal, newVal;
    struct node *curr;

    printf("\nEnter the old value to be modified: ");
    scanf("%d", &oldVal);

    printf("\nEnter the new value: ");
    scanf("%d", &newVal);

    if (head == NULL) 
	{
        printf("\nList is empty.\n");
        return;
    }

    curr = head;
    do {
        if (curr->data == oldVal) 
		{
            curr->data = newVal;
            printf("\nValue modified successfully.\n");
            return;
        }
        curr = curr->next;
    } while (curr != head);

    printf("\nValue not found in the list.\n");
}
