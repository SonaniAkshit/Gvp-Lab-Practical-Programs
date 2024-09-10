#include<stdio.h>
#include<stdlib.h>

void insert(int [], int *, int *);
void delete(int [], int *, int *);
void display(int [], int *, int *);
void modify(int [], int *, int *);

void main() {
    int front = -1, rear = -1, ch, q[5];
    int *f = &front, *r = &rear;

    while(1) 
    {
        printf("\n---MENU---");
        printf("\n 1. Enqueue");
        printf("\n 2. Dequeue");
        printf("\n 3. Display");
        printf("\n 4. Modify");
        printf("\n 5. EXIT");
        printf("\n----------");
        printf("\n Enter Your Choice: ");
        scanf("%d", &ch);
    
        switch(ch) 
        {
            case 1: 
                insert(q, f, r); 
                break;
            case 2: 
                delete(q, f, r); 
                break;
            case 3: 
                display(q, f, r); 
                break;
            case 4: 
                modify(q, f, r);
                break;
            case 5: 
                exit(0);
            default:
                printf("\nInvalid choice, please try again.");
        }
    }
}

void insert(int q[], int *f, int *r) 
{
    int n;
    if(*r == 4) 
    {
        printf("\nQueue is Overflow");
    } else {
        if(*f == -1 && *r == -1) 
        {
            *f = *r = 0;
        } 
        else 
        {
            (*r)++;
        }
        printf("\nEnter Element in Queue: ");
        scanf("%d", &n);
        q[*r] = n;
    }
}

void delete(int q[], int *f, int *r) 
{
    if(*f == -1) 
    {
        printf("\nQueue is Underflow...");
    } 
    else 
    {
        printf("\n%d is Deleted..", q[*f]);
        (*f)++;
        
        if(*f > *r) 
        {
            *f = *r = -1;
        }
    }
}

void display(int q[], int *f, int *r) 
{
    int i;
    if(*f == -1) 
    {
        printf("\nQueue is Underflow...");
    } 
    else 
    {
        for(i = *f; i <= *r; i++) 
        {
            printf("[%d] ", q[i]);
        }
    }
}

void modify(int q[], int *f, int *r) 
{
    int i,oldValue, newValue, found = 0;
    if(*f == -1) 
    {
        printf("\nQueue is Underflow...");
    } 
    else 
    {
        printf("\nEnter the old value to modify: ");
        scanf("%d", &oldValue);

        for(i = *f; i <= *r; i++) 
        {
            if(q[i] == oldValue) 
            {
                printf("\nEnter the new value: ");
                scanf("%d", &newValue);
                q[i] = newValue;
                printf("\nValue %d modified to %d at position %d", oldValue, newValue, i+1);
                found = 1;
                break;
            }
        }

        if(!found) 
        {
            printf("\nValue %d not found in the queue!", oldValue);
        }
    }
}