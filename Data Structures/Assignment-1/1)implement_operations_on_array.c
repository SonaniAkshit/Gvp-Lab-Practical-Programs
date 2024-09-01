#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

void addElement(int arr[], int *size);
void deleteElement(int arr[], int *size);
void modifyElement(int arr[], int size);
void sortArray(int arr[], int size);
void simpleSearch(int arr[], int size);
void displayArray(int arr[], int size);

void main() 
{
    int arr[SIZE], size = 0;
    int choice;
    
    while (1) {
        printf("\n=====Menu======\n");
        printf("1) Add\n");
        printf("2) Delete\n");
        printf("3) Modify\n");
        printf("4) Sort\n");
        printf("5) Simple Search\n");
        printf("6) Display\n");
        printf("7) Exit\n");
        printf("===============\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addElement(arr, &size);
                break;
            case 2:
                deleteElement(arr, &size);
                break;
            case 3:
                modifyElement(arr, size);
                break;
            case 4:
                sortArray(arr, size);
                break;
            case 5:
                simpleSearch(arr, size);
                break;
            case 6:
                displayArray(arr, size);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    getch();
}

void addElement(int arr[], int *size) 
{
    if (*size >= SIZE) 
	{
        printf("Array is full.\n");
        return;
    }
    printf("Enter value to add: ");
    scanf("%d", &arr[*size]);
    (*size)++;
}

void deleteElement(int arr[], int *size)
{
    int value, i, found = 0;
    if (*size == 0) 
	{
        printf("Array is empty.\n");
        return;
    }
    printf("Enter value to delete: ");
    scanf("%d", &value);
    for (i = 0; i < *size; i++) 
	{
        if (arr[i] == value) 
		{
            found = 1;
            break;
        }
    }
    if (found) 
	{
        for (; i < *size - 1; i++) 
		{
            arr[i] = arr[i + 1];
        }
        (*size)--;
        printf("Element deleted.\n");
    } 
	else 
	{
        printf("Element not found.\n");
    }
}

void modifyElement(int arr[], int size) 
{
    int oldValue, newValue, i, found = 0;
    if (size == 0) 
	{
        printf("Array is empty.\n");
        return;
    }
    printf("Enter old value to modify: ");
    scanf("%d", &oldValue);
    for (i = 0; i < size; i++) 
	{
        if (arr[i] == oldValue) 
		{
            printf("Enter new value: ");
            scanf("%d", &newValue);
            arr[i] = newValue;
            found = 1;
            break;
        }
    }
    if (found) 
	{
        printf("Element modified.\n");
        displayArray(arr, size);
    } 
	else 
	{
        printf("Element not found.\n");
    }
}

void sortArray(int arr[], int size) 
{
    int i, j, temp;
    if (size == 0) 
	{
        printf("Array is empty.\n");
        return;
    }
    for (i = 0; i < size - 1; i++) 
	{
        for (j = 0; j < size - i - 1; j++) 
		{
            if (arr[j] > arr[j + 1]) 
			{
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("Array sorted.\n");
    displayArray(arr, size);
}

void simpleSearch(int arr[], int size) 
{
    int value, i, found = 0;
    if (size == 0) 
	{
        printf("Array is empty.\n");
        return;
    }
    printf("Enter value to search: ");
    scanf("%d", &value);
    for (i = 0; i < size; i++) 
	{
        if (arr[i] == value) 
		{
            found = 1;
            break;
        }
    }
    if (found) 
	{
        printf("Element found at index %d.\n", i);
    } 
	else 
	{
        printf("Element not found.\n");
    }
}

void displayArray(int arr[], int size) 
{
    int i;
    if (size == 0) 
	{
        printf("Array is empty.\n");
        return;
    }
    printf("Array elements: ");
    for (i = 0; i < size; i++) 
	{
        printf("%d ", arr[i]);
    }
    printf("\n");
}

