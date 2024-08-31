#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

void insertFront(int[], int *, int *);
void insertRear(int[], int *, int *);
void deleteFront(int[], int *, int *);
void deleteRear(int[], int *, int *);
void modify(int[], int *, int *);
void display(int[], int *, int *);

void main() 
{
    int deque[SIZE];
    int front = -1, rear = -1;
    int choice;

    while (1) 
    {
        printf("\n===MENU===");
        printf("\n1) Insert at Front");
        printf("\n2) Insert at Rear");
        printf("\n3) Delete from Front");
        printf("\n4) Delete from Rear");
        printf("\n5) Modify");
        printf("\n6) Display");
        printf("\n7) EXIT");
        printf("\n==========");
        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);
        
        switch (choice) 
        {
            case 1:
                insertFront(deque, &front, &rear);
                break;
            case 2:
                insertRear(deque, &front, &rear);
                break;
            case 3:
                deleteFront(deque, &front, &rear);
                break;
            case 4:
                deleteRear(deque, &front, &rear);
                break;
            case 5:
                modify(deque, &front, &rear);
                break;
            case 6:
                display(deque, &front, &rear);
                break;
            case 7:
                exit(0);
            default:
                printf("You Entered Wrong Choice...");
        }
    }

    getch();
}

void insertFront(int deque[], int *front, int *rear) 
{
    int value;
    if ((*front == 0 && *rear == SIZE - 1) || (*front == *rear + 1)) 
    {
        printf("\nOverflow! Deque is full...\n");
    } 
    else 
    {
        printf("Enter value to insert at Front: ");
        scanf("%d", &value);
        if (*front == -1) 
        {
            *front = *rear = 0;
        } 
        else if (*front == 0) 
        {
            *front = SIZE - 1;
        } 
        else 
        {
            (*front)--;
        }
        deque[*front] = value;
    }
}

void insertRear(int deque[], int *front, int *rear) 
{
    int value;
    if ((*front == 0 && *rear == SIZE - 1) || (*front == *rear + 1)) 
    {
        printf("\nOverflow! Deque is full...\n");
    } 
    else 
    {
        printf("Enter value to insert at Rear: ");
        scanf("%d", &value);
        if (*front == -1) 
        {
            *front = *rear = 0;
        } 
        else if (*rear == SIZE - 1) 
        {
            *rear = 0;
        } 
        else 
        {
            (*rear)++;
        }
        deque[*rear] = value;
    }
}

void deleteFront(int deque[], int *front, int *rear) 
{
    if (*front == -1) 
    {
        printf("\nUnderflow! Deque is empty...\n");
    } 
    else 
    {
        printf("\n%d is deleted from Front...\n", deque[*front]);
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

void deleteRear(int deque[], int *front, int *rear) 
{
    if (*rear == -1) 
    {
        printf("\nUnderflow! Deque is empty...\n");
    } 
    else 
    {
        printf("\n%d is deleted from Rear...\n", deque[*rear]);
        if (*front == *rear) 
        {
            *front = *rear = -1;
        } 
        else if (*rear == 0) 
        {
            *rear = SIZE - 1;
        } 
        else 
        {
            (*rear)--;
        }
    }
}

void modify(int deque[], int *front, int *rear) 
{
    int i,oldval, newval, found = 0;
    if (*front == -1) 
    {
        printf("\nDeque is empty.\n");
    } 
    else 
    {
        printf("\nEnter the old value to modify: ");
        scanf("%d", &oldval);

        for (i = *front;; i = (i + 1) % SIZE) 
        {
            if (deque[i] == oldval) 
            {
                found = 1;
                printf("\nEnter the new value: ");
                scanf("%d", &newval);
                deque[i] = newval;
                printf("\nValue %d modified to %d.\n", oldval, newval);
                break;
            }
            if (i == *rear) 
                break;
        }

        if (!found) 
        {
            printf("\nValue %d not found in Deque.\n", oldval);
        }
    }
}

void display(int deque[], int *front, int *rear) 
{
	int i;
    if (*front == -1) 
    {
        printf("\nDeque is empty.\n");
    } 
    else 
    {
        printf("\n----DEQUE----\n");
        for (i = *front;; i = (i + 1) % SIZE) 
        {
            printf("[%d] ", deque[i]);
            if (i == *rear) 
                break;
        }
        printf("\n--------------\n");
    }
}
