#include <stdio.h>
#include <ctype.h>

int precedence(char ch) 
{
    switch (ch) 
	{
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return -1;
    }
}

void push(char stack[], int *top, char data) 
{
    if (*top == 99)
	{
        printf("\nStack Overflow!\n");
    } 
	else 
	{
        *top += 1;
        stack[*top] = data;
    }
}

char pop(char stack[], int *top) 
{
    if (*top == -1) 
	{
        printf("\nStack Underflow!\n");
        return '\0';
    } 
	else 
	{
        char data = stack[*top];
        *top -= 1;
        return data;
    }
}

void infixToPostfix(char infix[]) 
{
    int i, top = -1;
    char stack[100];
    char postfix[100];
    int j = 0;

    for (i = 0; infix[i] != '\0'; i++)
	{
        if (isalnum(infix[i])) 
		{
            postfix[j++] = infix[i];
        } 
		else if (infix[i] == '(') 
		{
            push(stack, &top, infix[i]);
        } 
		else if (infix[i] == ')') 
		{
            while (top != -1 && stack[top] != '(') 
			{
                postfix[j++] = pop(stack, &top);
            }
            pop(stack, &top);
        } 
		else 
		{
            while (top != -1 && precedence(infix[i]) <= precedence(stack[top])) 
			{
                postfix[j++] = pop(stack, &top);
            }
            push(stack, &top, infix[i]);
        }
    }

    while (top != -1) 
	{
        postfix[j++] = pop(stack, &top);
    }
    postfix[j] = '\0';

    printf("Postfix expression: %s\n", postfix);
}

void main()
{
    char infix[10];
    printf("Enter infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix);
    getch();
}

