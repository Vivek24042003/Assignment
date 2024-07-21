#include <stdio.h>

#define MAX 100  // Define maximum stack size

int stack[MAX], top = -1, n;  // Stack array, top index, and stack size

void push(void);
void pop(void);
void display(void);

int main() {
    int choice;

    printf("\nEnter the size of the STACK (MAX=%d): ", MAX);
    scanf("%d", &n);

    if (n <= 0 || n > MAX) {
        printf("\nInvalid stack size. It should be between 1 and %d.\n", MAX);
        return 1;  // Exit the program with an error code
    }

    printf("\n\tSTACK OPERATIONS USING ARRAY");
    printf("\n\t------------------------------");
    printf("\n\t1. PUSH\n\t2. POP\n\t3. DISPLAY\n\t4. EXIT");

    do {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\n\tEXIT POINT");
                break;
            default:
                printf("\n\tPlease enter a valid choice (1/2/3/4).");
        }
    } while (choice != 4);

    return 0;
}

void push() {
    if (top >= n - 1) {
        printf("\n\tSTACK is overflow.");
    } else {
        int x;
        printf("Enter a value to be pushed: ");
        scanf("%d", &x);
        stack[++top] = x;
        printf("\n\t%d pushed to stack.", x);
    }
}

void pop() {
    if (top < 0) {
        printf("\n\tSTACK is underflow.");
    } else {
        printf("\n\tThe popped element is %d.", stack[top--]);
    }
}

void display() {
    if (top >= 0) {
        printf("\nThe elements in the STACK are:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    } else {
        printf("\n\tThe STACK is empty.");
    }
}
