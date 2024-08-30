#include <stdio.h>
#include <stdlib.h>

void addElement(int arr[], int *size, int capacity);
void deleteElement(int arr[], int *size, int value);
void modifyElement(int arr[], int size, int oldValue, int newValue);
void sortArray(int arr[], int size);
void simpleSearch(int arr[], int size, int value);
void binarySearch(int arr[], int size, int value);
void displayArray(int arr[], int size);

int main() {
    int arr[5], size = 0, capacity = 5;
    int choice, value, oldValue, newValue;
    
    do {
        printf("\n=====Menu======\n");
        printf("1) Add\n");
        printf("2) Delete\n");
        printf("3) Modify\n");
        printf("4) Sort\n");
        printf("5) Simple Search\n");
        printf("6) Binary Search\n");
        printf("7) Display\n");
        printf("8) Exit\n");
        printf("\n===============\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                addElement(arr, &size, capacity);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteElement(arr, &size, value);
                break;
            case 3:
                printf("Enter old value to modify: ");
                scanf("%d", &oldValue);
                printf("Enter new value: ");
                scanf("%d", &newValue);
                modifyElement(arr, size, oldValue, newValue);
                break;
            case 4:
                sortArray(arr, size);
                break;
            case 5:
                printf("Enter value to search: ");
                scanf("%d", &value);
                simpleSearch(arr, size, value);
                break;
            case 6:
                sortArray(arr, size); // Binary search requires sorted array
                printf("Enter value to search: ");
                scanf("%d", &value);
                binarySearch(arr, size, value);
                break;
            case 7:
                displayArray(arr, size);
                break;
            case 8:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        
    } while (choice != 8);

    return 0;
}

// Function to add an element to the array
void addElement(int arr[], int *size, int capacity) {
    if (*size >= capacity) {
        printf("Array is full.\n");
        return;
    }
    printf("Enter value to add: ");
    scanf("%d", &arr[*size]);
    (*size)++;
}

// Function to delete an element from the array
void deleteElement(int arr[], int *size, int value) {
    int i, found = 0;
    for (i = 0; i < *size; i++) {
        if (arr[i] == value) {
            found = 1;
            break;
        }
    }
    if (found) {
        for (; i < *size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        (*size)--;
        printf("Element deleted.\n");
    } else {
        printf("Element not found.\n");
    }
}

// Function to modify an element in the array
void modifyElement(int arr[], int size, int oldValue, int newValue) {
    int i, found = 0;
    for (i = 0; i < size; i++) {
        if (arr[i] == oldValue) {
            arr[i] = newValue;
            found = 1;
            break;
        }
    }
    if (found) {
        printf("Element modified.\n");
    } else {
        printf("Element not found.\n");
    }
}

// Function to sort the array using bubble sort
void sortArray(int arr[], int size) {
    int i, j, temp;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("Array sorted.\n");
}

// Function for simple search
void simpleSearch(int arr[], int size, int value) {
    int i, found = 0;
    for (i = 0; i < size; i++) {
        if (arr[i] == value) {
            found = 1;
            break;
        }
    }
    if (found) {
        printf("Element found at index %d.\n", i);
    } else {
        printf("Element not found.\n");
    }
}

// Function for binary search
void binarySearch(int arr[], int size, int value) {
    int left = 0, right = size - 1, mid;
    while (left <= right) {
        mid = (left + right) / 2;
        if (arr[mid] == value) {
            printf("Element found at index %d.\n", mid);
            return;
        } else if (arr[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    printf("Element not found.\n");
}

// Function to display the elements of the array
void displayArray(int arr[], int size) {
    int i;
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Array elements: ");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

