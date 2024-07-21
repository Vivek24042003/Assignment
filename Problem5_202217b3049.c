#include <stdio.h>
#include <stdlib.h> // For exit()

#define SIZE 5

void enqueue(int queue[], int *rear, int *front, int *item_count);
void dequeue(int queue[], int *front, int *item_count);
void display(int queue[], int front, int rear);

int main() {
    int queue[SIZE];
    int choice = 0;
    int front = 0, rear = 0;
    int item_count = 0; // Number of items in the queue

    printf("Queue using Array");
    printf("\n1.Insertion \n2.Deletion \n3.Display \n4.Exit");

    while (1) {
        printf("\nEnter the Choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                enqueue(queue, &rear, &front, &item_count);
                break;
            case 2:
                dequeue(queue, &front, &item_count);
                break;
            case 3:
                display(queue, front, rear);
                break;
            case 4:
                printf("\nExiting...\n");
                exit(0);
            default:
                printf("Wrong Choice: Please see the options\n");
        }
    }
    return 0;
}

void enqueue(int queue[], int *rear, int *front, int *item_count) {
    if (*item_count == SIZE) {
        printf("\nQueue is Full\n");
    } else {
        int item;
        printf("\nEnter the number to insert: ");
        scanf("%d", &item);
        queue[*rear] = item;
        (*rear)++;
        (*item_count)++;
    }
}

void dequeue(int queue[], int *front, int *item_count) {
    if (*item_count == 0) {
        printf("\nQueue is Empty\n");
    } else {
        printf("\nDeleted Element is %d\n", queue[*front]);
        (*front)++;
        (*item_count)--;
    }
}

void display(int queue[], int front, int rear) {
    if (front == rear) {
        printf("\nQueue is Empty\n");
    } else {
        printf("\nQueue Elements are:\n");
        for (int i = front; i < rear; i++) {
            printf("%d\n", queue[i]);
        }
    }
}
