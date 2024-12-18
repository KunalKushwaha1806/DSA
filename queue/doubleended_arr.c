#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct {
    int arr[MAX];
    int front, rear;
} Deque;

void initDeque(Deque *dq) {
    dq->front = -1;
    dq->rear = -1;
}

int isFull(Deque *dq) {
    return (dq->front == 0 && dq->rear == MAX - 1) || (dq->front == dq->rear + 1);
}

int isEmpty(Deque *dq) {
    return dq->front == -1;
}

void insertFront(Deque *dq, int value) {
    if (isFull(dq)) {
        printf("Deque is full!\n");
        return;
    }
    if (dq->front == -1) { // First element
        dq->front = dq->rear = 0;
    } else if (dq->front == 0) {
        dq->front = MAX - 1; // Wrap around
    } else {
        dq->front--;
    }
    dq->arr[dq->front] = value;
}

void insertRear(Deque *dq, int value) {
    if (isFull(dq)) {
        printf("Deque is full!\n");
        return;
    }
    if (dq->front == -1) { // First element
        dq->front = dq->rear = 0;
    } else if (dq->rear == MAX - 1) {
        dq->rear = 0; // Wrap around
    } else {
        dq->rear++;
    }
    dq->arr[dq->rear] = value;
}

int deleteFront(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty!\n");
        return -1;
    }
    int item = dq->arr[dq->front];
    if (dq->front == dq->rear) { // Reset deque
        dq->front = dq->rear = -1;
    } else if (dq->front == MAX - 1) {
        dq->front = 0; // Wrap around
    } else {
        dq->front++;
    }
    return item;
}

int deleteRear(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty!\n");
        return -1;
    }
    int item = dq->arr[dq->rear];
    if (dq->front == dq->rear) { // Reset deque
        dq->front = dq->rear = -1;
    } else if (dq->rear == 0) {
        dq->rear = MAX - 1; // Wrap around
    } else {
        dq->rear--;
    }
    return item;
}

void displayDeque(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty!\n");
        return;
    }
    printf("Deque: ");
    int i = dq->front;
    while (1) {
        printf("%d ", dq->arr[i]);
        if (i == dq->rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    Deque dq;
    initDeque(&dq);

    int choice, value;
    do {
        printf("\n1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n5. Display\n6. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &value);
                insertFront(&dq, value);
                break;
            case 2:
                printf("Enter value to insert at rear: ");
                scanf("%d", &value);
                insertRear(&dq, value);
                break;
            case 3:
                printf("Deleted from front: %d\n", deleteFront(&dq));
                break;
            case 4:
                printf("Deleted from rear: %d\n", deleteRear(&dq));
                break;
            case 5:
                displayDeque(&dq);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 6);

    return 0;
}
