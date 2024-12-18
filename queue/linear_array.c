#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
    int arr[MAX];
    int front, rear;
} ArrayQueue;

void initQueue(ArrayQueue *q) {
    q->front = -1;
    q->rear = -1;
}

int isFull(ArrayQueue *q) {
    return q->rear == MAX - 1;
}

int isEmpty(ArrayQueue *q) {
    return q->front == -1 || q->front > q->rear;
}

void enqueue(ArrayQueue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }
    if (q->front == -1) q->front = 0;
    q->rear++;
    q->arr[q->rear] = value;
}

int dequeue(ArrayQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int item = q->arr[q->front];
    q->front++;
    if (q->front > q->rear) { // Reset the queue
        q->front = q->rear = -1;
    }
    return item;
}

void display(ArrayQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int main() {
    ArrayQueue q;
    initQueue(&q);

    int choice, value;
    do {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                printf("Dequeued: %d\n", dequeue(&q));
                break;
            case 3:
                display(&q);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}
