#include <stdio.h>
#include <conio.h>

struct Student {
    char name[50];
    int number;
    float percentage;
};

void insert(struct Student S[], int n) {
	int i;
    for (i = 0; i < n; i++) {
        printf("Enter name of student %d: ", i + 1);
        scanf("%s", S[i].name);
        printf("Enter number of student %d: ", i + 1);
        scanf("%d", &S[i].number);
        printf("Enter percentage of student %d: ", i + 1);
        scanf("%f", &S[i].percentage);
        printf("\n");
    }
}

void display(struct Student S[], int n) {
	int i;
    printf("\n%-20s %-10s %-10s\n", "Name", "Number", "Percentage");
    for (i = 0; i < n; i++) {
        printf("%-20s %-10d %-10.2f\n", S[i].name, S[i].number, S[i].percentage);
    }
}

void sort(struct Student S[], int n) {
	int i;
    for (i = 1; i < n; i++) {
        struct Student temp = S[i];
        int j = i - 1;
        while (j >= 0 && S[j].percentage < temp.percentage) {
            S[j + 1] = S[j];
            j--;
        }
        S[j + 1] = temp;
    }
}
void main() 
{
    int n;
    
    printf("Enetr Value You Want To Insert Student Record.:");
    scanf("%d",&n);
    struct Student S[n];

    insert(S, n);
    sort(S, n);
    display(S, n);

    getch();
}
