#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

void push1(int[], int *, int *);
void push2(int[], int *, int *);
void pop1(int[], int *);
void pop2(int[], int *);
void peep1(int[], int *);
void peep2(int[], int *);
void modify1(int[], int *);
void modify2(int[], int *);
void display(int[], int *, int *);

void main() 
{
    int top1 = -1, top2 = SIZE;
    int stack[SIZE];
    int *t1 = &top1, *t2 = &top2;
    int ch;

    while (1) 
    {
        printf("\n===MENU===");
        printf("\n1) Push to Stack 1.");
        printf("\n2) Push to Stack 2.");
        printf("\n3) Pop from Stack 1.");
        printf("\n4) Pop from Stack 2.");
        printf("\n5) Peep Stack 1.");
        printf("\n6) Peep Stack 2.");
        printf("\n7) Modify Stack 1.");
        printf("\n8) Modify Stack 2.");
        printf("\n9) Display.");
        printf("\n10) EXIT");
        printf("\n==========");
        printf("\nEnter Your Choice: ");
        scanf("%d", &ch);
        
        switch (ch) 
        {
            case 1:
                push1(stack, t1, t2);
                break;
            case 2:
                push2(stack, t2, t1);
                break;
            case 3:
                pop1(stack, t1);
                break;
            case 4:
                pop2(stack, t2);
                break;
            case 5:
                peep1(stack, t1);
                break;
            case 6:
                peep2(stack, t2);
                break;
            case 7:
                modify1(stack, t1);
                break;
            case 8:
                modify2(stack, t2);
                break;
            case 9:
                display(stack, t1, t2);
                break;
            case 10:
                exit(0);
            default:
                printf("You Entered Wrong Choice...");
        }
    }
}

void push1(int stack[], int *top1, int *top2) 
{
    int value;
    if (*top1 + 1 == *top2) 
    {
        printf("\nOverflow! Stack 1 is full...\n");
    } 
    else 
    {
        printf("Enter value to push to Stack 1: ");
        scanf("%d", &value);
        *top1 += 1;
        stack[*top1] = value;
    }
}

void push2(int stack[], int *top2, int *top1) 
{
    int value;
    if (*top2 - 1 == *top1) 
    {
        printf("\nOverflow! Stack 2 is full...\n");
    } 
    else 
    {
        printf("Enter value to push to Stack 2: ");
        scanf("%d", &value);
        *top2 -= 1;
        stack[*top2] = value;
    }
}

void pop1(int stack[], int *top1) 
{
    if (*top1 == -1) 
    {
        printf("\nUnderflow! Stack 1 is empty...\n");
    } 
    else 
    {
        printf("\n%d is popped from Stack 1...\n", stack[*top1]);
        *top1 -= 1;
    }
}

void pop2(int stack[], int *top2) 
{
    if (*top2 == SIZE) 
    {
        printf("\nUnderflow! Stack 2 is empty...\n");
    } 
    else 
    {
        printf("\n%d is popped from Stack 2...\n", stack[*top2]);
        *top2 += 1;
    }
}

void peep1(int stack[], int *top1) 
{
    if (*top1 == -1) 
    {
        printf("\nStack 1 is empty.\n");
    } 
    else 
    {
        printf("Top element of Stack 1: %d\n", stack[*top1]);
    }
}

void peep2(int stack[], int *top2) 
{
    if (*top2 == SIZE) 
    {
        printf("\nStack 2 is empty.\n");
    } 
    else 
    {
        printf("Top element of Stack 2: %d\n", stack[*top2]);
    }
}

void modify1(int stack[], int *top1) 
{
    int i,oldval, newval, found = 0;
    if (*top1 == -1) 
    {
        printf("\nStack 1 is empty.\n");
    } 
    else 
    {
        printf("\nEnter the old value to modify in Stack 1: ");
        scanf("%d", &oldval);
        
        for (i = 0; i <= *top1; i++) 
        {
            if (stack[i] == oldval) 
            {
                found = 1;
                printf("\nEnter the new value: ");
                scanf("%d", &newval);
                stack[i] = newval;
                printf("\nValue %d at position %d in Stack 1 modified to %d.\n", oldval, i, newval);
                break;
            }
        }

        if (!found) 
        {
            printf("\nValue %d not found in Stack 1.\n", oldval);
        }
    }
}

void modify2(int stack[], int *top2) 
{
    int i,oldval, newval, found = 0;
    if (*top2 == SIZE) 
    {
        printf("\nStack 2 is empty.\n");
    } 
    else 
    {
        printf("\nEnter the old value to modify in Stack 2: ");
        scanf("%d", &oldval);
        
        for (i = SIZE - 1; i >= *top2; i--) 
        {
            if (stack[i] == oldval) 
            {
                found = 1;
                printf("\nEnter the new value: ");
                scanf("%d", &newval);
                stack[i] = newval;
                printf("\nValue %d at position %d in Stack 2 modified to %d.\n", oldval, i, newval);
                break;
            }
        }

        if (!found) 
        {
            printf("\nValue %d not found in Stack 2.\n", oldval);
        }
    }
}

void display(int stack[], int *top1, int *top2) 
{
    int i;
    printf("\n----STACK 1----\n");
    if (*top1 == -1) 
    {
        printf("Stack 1 is empty.\n");
    } 
    else 
    {
        for (i = *top1; i >= 0; i--) 
        {
            printf("[%d] ", stack[i]);
        }
        printf("\n");
    }

    printf("\n----STACK 2----\n");
    if (*top2 == SIZE) 
    {
        printf("Stack 2 is empty.\n");
    } 
    else 
    {
        for (i = SIZE - 1; i >= *top2; i--) 
        {
            printf("[%d] ", stack[i]);
        }
        printf("\n");
    }
}

