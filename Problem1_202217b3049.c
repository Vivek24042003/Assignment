#include<stdio.h>
#include<stdlib.h>  // Include stdlib.h for exit()
#define MAX 10

// Function prototypes
void create();
void insert();
void deletion();
void search();
void display();

// Global variables
int b[MAX]; // Using MAX as the maximum size of the list
int n, p, e, i, pos; // Variables for list size, element to insert/delete, position, and loop counters

int main() {
    int ch;
    char g = 'y';

    do {
        printf("\nMain Menu");
        printf("\n1. Create");
        printf("\n2. Delete");
        printf("\n3. Search");
        printf("\n4. Insert");
        printf("\n5. Display");
        printf("\n6. Exit");
        printf("\n\nEnter your Choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1:
                create();
                break;
            case 2:
                deletion();
                break;
            case 3:
                search();
                break;
            case 4:
                insert();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("\nExiting the program.\n");
                exit(0); // Terminate the program
                break;
            default:
                printf("\nInvalid choice. Please enter a number between 1 and 6.\n");
        }

        printf("\nDo you want to continue (y/n)? ");
        scanf(" %c", &g);
    } while (g == 'y' || g == 'Y');

    return 0;
}

void create() {
    printf("\nEnter the number of elements to create: ");
    scanf("%d", &n);

    if (n > MAX) {
        printf("Cannot create more than %d elements.\n", MAX);
        return;
    }

    for (i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &b[i]);
    }
}

void deletion() {
    if (n == 0) {
        printf("\nList is empty. Nothing to delete.\n");
        return;
    }

    printf("\nEnter the position to delete (0 to %d): ", n - 1);
    scanf("%d", &pos);

    if (pos < 0 || pos >= n) {
        printf("Invalid position. Deletion failed.\n");
        return;
    }

    for (i = pos; i < n - 1; i++) {
        b[i] = b[i + 1];
    }

    n--;

    printf("Element deleted successfully.\n");
}

void search() {
    if (n == 0) {
        printf("\nList is empty. Nothing to search.\n");
        return;
    }

    printf("\nEnter the element to search: ");
    scanf("%d", &e);

    for (i = 0; i < n; i++) {
        if (b[i] == e) {
            printf("Element %d found at position %d.\n", e, i);
            return;
        }
    }

    printf("Element %d not found in the list.\n", e);
}

void insert() {
    if (n >= MAX) {
        printf("\nList is full. Cannot insert more elements.\n");
        return;
    }

    printf("\nEnter the position to insert (0 to %d): ", n);
    scanf("%d", &pos);

    if (pos < 0 || pos > n) {
        printf("Invalid position. Insertion failed.\n");
        return;
    }

    printf("Enter the element to insert: ");
    scanf("%d", &p);

    for (i = n - 1; i >= pos; i--) {
        b[i + 1] = b[i];
    }

    b[pos] = p;
    n++;

    printf("Element inserted successfully.\n");
}

void display() {
    if (n == 0) {
        printf("\nList is empty. Nothing to display.\n");
        return;
    }

    printf("\nElements in the list:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", b[i]);
    }
    printf("\n");
}
