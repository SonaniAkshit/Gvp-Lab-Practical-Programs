#include <stdio.h>
#include <conio.h>
#define SIZE 5

void push(int[], int *);
void pop(int[], int *);
void peep(int[], int *);
void display(int[], int *);
void modify(int[], int *);

void main() 
{
    int x = -1;
    int stack[SIZE], *top = &x;
    int ch;
    while (1) 
	{
        printf("\n===MENU===");
        printf("\n1) Push.");
        printf("\n2) POP.");
        printf("\n3) Peep.");
        printf("\n4) Display.");
        printf("\n5) Modify.");
        printf("\n6) EXIT");
        printf("\n==========");
        printf("\nEnter Your Choice:");
        scanf("%d", &ch);
        
        switch (ch) 
		{
            case 1:
                push(stack, top);
                break;
            case 2:
                pop(stack, top);
                break;
            case 3:
                peep(stack, top);
                break;
            case 4:
                display(stack, top);
                break;
            case 5:
                modify(stack, top);
                break;
            case 6:
                exit(0);
            default:
                printf("You Entered Wrong Choice...");
        }
    }
    getch();
}
void push(int stack[], int *top)
 {
    int stackele;
    if (*top == SIZE - 1) 
	{
        printf("\nOverflow! Stack is Full...");
    } 
	else
	{
        printf("\nEnter Value You Want To Insert Into Stack:");
        scanf("%d", &stackele);
        *top += 1;
        stack[*top] = stackele;
    }
}

void display(int stack[], int *top) 
{
    int i;
    printf("\n----STACK----\n");
    if (*top == -1) 
	{
        printf("Stack is empty.\n");
    } 
	else
	 {
        for (i = *top; i >= 0; i--) 
		{
            printf("[%d]", stack[i]);
        }
    }
    printf("\n-------------");
}

void pop(int stack[], int *top)
 {
    if (*top == -1) 
	{
        printf("\nUnderflow! Stack is empty...\n");
    } 
	else
	{
        printf("\n%d is popped...\n", stack[*top]);
        *top -= 1;
    }
}

void peep(int stack[], int *top) 
{
    if (*top == -1) 
	{
        printf("\nStack is empty.\n");
    } 
	else 
	{
        printf("Top element: %d\n", stack[*top]);
    }
}

void modify(int stack[], int *top) 
{
    int oldval, newval, i, found = 0;
    if (*top == -1) 
	{
        printf("\nStack is empty.\n");
    } 
	else 
	{
        printf("\nEnter the old value to modify: ");
        scanf("%d", &oldval);
        
        for (i = 0; i <= *top; i++) 
		{
            if (stack[i] == oldval) 
			{
                found = 1;
                printf("\nEnter the new value: ");
                scanf("%d", &newval);
                stack[i] = newval;
                printf("\nValue %d at position %d modified to %d.\n", oldval, i, newval);
                break;
            }
        }

        if (!found) 
		{
            printf("\nValue %d not found in the stack.\n", oldval);
        }
    }
}
