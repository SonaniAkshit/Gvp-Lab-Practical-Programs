#include<stdio.h>
# define MAX 5

void add(int [],int *);
void display(int[],int *);
void delete(int[],int *);
void modify(int[],int *);
void sort(int[],int *);
int count;

void main()
{
	int x = 0, arr[MAX], *ele = &x, ch;
	
	while(1)
	{
		printf("\n===MENU===");
		printf("\n1)ADD.");
		printf("\n2)Display.");
		printf("\n3)Delete.");
		printf("\n4)Modify.");	
		printf("\n5)Sort.");			
		printf("\n6)count elements.");
		printf("\n7)Exit.");
		printf("\n----------");
		printf("\nEnter Any Choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: add(arr,ele); break;
			case 2: display(arr,ele); break;
			case 3: delete(arr,ele); break;
			case 4: modify(arr,ele); break;
			case 5: printf("count:%d",count); break;
			case 6: exit(0);
		}
	}
}
void add(int arr[],int *ele)
{
	int n;
	if(*ele == MAX)
	{
		printf("\nArray is full");
	}
	else
	{
		printf("\nEnter Any Element: ");
		scanf("%d",&n);
		
		arr[*ele]=n;
		(*ele)++;
		count++;
		
		printf("\nElement: %d",n);
	}
}
void display(int arr[],int *ele)
{
	int i;
	if(*ele == 0)
	{
		printf("\nArray is empty.");
	}
	else
	{
		printf("\nArray Elements:");
		for(i=0;i<*ele;i++)
		{
			printf(" %d",arr[i]);
		}
	}
}
void delete(int arr[],int *ele)
{
	int i, j, val, fd = 0;
	if(*ele == 0)
	{
		printf("\nArray is empty.");
	}
	else
	{
		display(arr,ele);
		
		printf("\nEnter value to delete: ");
		scanf("%d",&val);
		
		for (i = 0; i < *ele; i++) 
		{
    		if (arr[i] == val) 
			{
        		for (j = i; j < *ele - 1; j++) 
				{
            		arr[j] = arr[j + 1];
        		}
        		(*ele)--;
        		count--;
        		printf("%d is deleted\n", arr[i]);
        		break;
    		}
    		else
    		{
    			printf("\nNot found..\n");
    			break;
			}
		}
	}
}
void modify(int arr[], int *ele)
{
	int i,oldval,newval;
	if(*ele == 0)
	{
		printf("\nArray is empty.");
	}
	else
	{
		display(arr,ele);
		
		printf("\nEnter old value:");
		scanf("%d",&oldval);
		for(i=0;i<*ele;i++)
		{
			if(arr[i] == oldval)
			{
				printf("Enter new value:");
				scanf("%d",&newval);
				arr[i] = newval;
				break;
			}
			else
			{
				printf("\nNot found");
				break;
			}
		}
		display(arr,ele);
	}
}
void sort(int arr[],int *ele)
{
	int i,j,temp;
	
	if(*ele==0)
	{
		printf("Array is empty.");
	}
	else
	{
		
	}
}
