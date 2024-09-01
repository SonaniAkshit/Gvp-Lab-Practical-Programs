#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

void insert(int[], int *, int *);
void delete(int[], int *, int *);
void modify(int[], int *, int *);
void display(int[], int *, int *);

void main() 
{
    int queue[SIZE];
    int front = -1, rear = -1;
    int choice;

    while (1) 
    {
        printf("\n===MENU===");
        printf("\n1) Insert");
        printf("\n2) Delete");
        printf("\n3) Modify");
        printf("\n4) Display");
        printf("\n5) EXIT");
        printf("\n==========");
        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);
        
        switch (choice) 
        {
            case 1:
                insert(queue, &front, &rear);
                break;
            case 2:
                delete(queue, &front, &rear);
                break;
            case 3:
                modify(queue, &front, &rear);
                break;
            case 4:
                display(queue, &front, &rear);
                break;
            case 5:
                exit(0);
            default:
                printf("You Entered Wrong Choice...\n");
        }
    }

    getch();
}

void insert(int queue[], int *front, int *rear) 
{
    int value;
    if ((*front == 0 && *rear == SIZE - 1) || (*rear + 1 == *front)) 
    {
        printf("\nOverflow! Queue is full...\n");
    } 
    else 
    {
        printf("Enter value to insert: ");
        scanf("%d", &value);
        if (*front == -1) 
        {
            *front = *rear = 0;
        } 
        else if (*rear == SIZE - 1 && *front != 0) 
        {
            *rear = 0;
        } 
        else 
        {
            (*rear)++;
        }
        queue[*rear] = value;
    }
}

void delete(int queue[], int *front, int *rear) 
{
    if (*front == -1) 
    {
        printf("\nUnderflow! Queue is empty...\n");
    } 
    else 
    {
        printf("\n%d is deleted from Queue...\n", queue[*front]);
        if (*front == *rear) 
        {
            *front = *rear = -1;
        } 
        else if (*front == SIZE - 1) 
        {
            *front = 0;
        } 
        else 
        {
            (*front)++;
        }
    }
}

void modify(int queue[], int *front, int *rear) 
{
    int i,oldval, newval, found = 0;
    if (*front == -1) 
    {
        printf("\nQueue is empty.\n");
    } 
    else 
    {
        printf("\nEnter the old value to modify: ");
        scanf("%d", &oldval);

        for (i = *front;; i = (i + 1) % SIZE) 
        {
            if (queue[i] == oldval) 
            {
                found = 1;
                printf("\nEnter the new value: ");
                scanf("%d", &newval);
                queue[i] = newval;
                printf("\nValue %d modified to %d.\n", oldval, newval);
                break;
            }
            if (i == *rear) 
                break;
        }

        if (!found) 
        {
            printf("\nValue %d not found in Queue.\n", oldval);
        }
    }
}

void display(int queue[], int *front, int *rear) 
{
	int i;
    if (*front == -1) 
    {
        printf("\nQueue is empty.\n");
    } 
    else 
    {
        printf("\n----QUEUE----\n");
        for (i = *front;; i = (i + 1) % SIZE) 
        {
            printf("[%d] ", queue[i]);
            if (i == *rear) 
                break;
        }
        printf("\n--------------\n");
    }
}
