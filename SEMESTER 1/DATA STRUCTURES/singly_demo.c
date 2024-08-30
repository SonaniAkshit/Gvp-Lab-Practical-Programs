#include <stdio.h>
#include <stdlib.h>  

struct node {
    int data;
    struct node *next;
};

void insert_node(struct node **head, int data);
void display_node(struct node *head);
void delete_node(struct node **head, int data);

void main() {
    int ch, data;
    struct node *head = NULL;

    while (1) {  // Loop for the menu
        printf("\n=====MENU=====\n");	
        printf("\n1. Insert First.");	
        printf("\n2. Display.");	
        printf("\n3. Delete First.");	
        printf("\n4. Exit.");	
        printf("\n==============\n");	
        printf("Enter Your Choice: ");
        scanf("%d", &ch);
	
        switch(ch) {
            case 1: 
                printf("Enter Any Element: ");
                scanf("%d", &data);
                insert_node(&head, data);
                break;
            
            case 2: 
                display_node(head);
                break;
            
            case 3:
                delete_node(&head, data); 
                break;
            
            case 4: 
                exit(0);
            
            default:
                printf("Invalid Choice! Try Again.\n");
        }
    }
}

void insert_node(struct node **head, int data) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
    printf("\nElement Inserted in Node...\n");
}

void display_node(struct node *head) {
    struct node *temp = head;
    printf("\n");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void delete_node(struct node **head, int data) {
    if (*head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }
    struct node *temp = *head;
    *head = (*head)->next;
    free(temp);
    printf("First node deleted successfully.\n");
}

