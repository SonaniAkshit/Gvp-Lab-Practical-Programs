#include <stdio.h>
#include <ctype.h>  // Use ctype.h for isalnum function

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
    if (*top == 99)  // Change 100 to 99 because array index goes from 0 to 99
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
        return '\0';  // Return a null character to handle the error case
    } 
	else 
	{
        char data = stack[*top];
        *top -= 1;  // Fix to decrement top instead of setting it to -1
        return data;
    }
}

void infixToPostfix(char infix[]) 
{
    int i, top = -1;
    char stack[100];
    char postfix[100];
    int j = 0;

    for (i = 0; infix[i] != '\0'; i++)  // Change semicolon to null character for string end
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
            pop(stack, &top);  // Pop the '(' from the stack
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
    postfix[j] = '\0';  // End the postfix string with a null character

    printf("Postfix expression: %s\n", postfix);
}

int main()  // Change main to int main() and return 0 at the end
{
    char infix[100];
    printf("Enter infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix);
    return 0;  // Return 0 to indicate successful execution
}

