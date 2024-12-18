#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct {
    int data[MAX];
    int priority[MAX];
    int size;
} PriorityQueue;

void initQueue(PriorityQueue *pq) {
    pq->size = 0;
}

int isFull(PriorityQueue *pq) {
    return pq->size == MAX;
}

int isEmpty(PriorityQueue *pq) {
    return pq->size == 0;
}

void enqueue(PriorityQueue *pq, int value, int prio) {
    if (isFull(pq)) {
        printf("Priority Queue is full!\n");
        return;
    }
    int i = pq->size - 1;
    // Shift elements to maintain priority order
    while (i >= 0 && pq->priority[i] > prio) {
        pq->data[i + 1] = pq->data[i];
        pq->priority[i + 1] = pq->priority[i];
        i--;
    }
    pq->data[i + 1] = value;
    pq->priority[i + 1] = prio;
    pq->size++;
}

int dequeue(PriorityQueue *pq) {
    if (isEmpty(pq)) {
        printf("Priority Queue is empty!\n");
        return -1;
    }
    int item = pq->data[0];
    for (int i = 0; i < pq->size - 1; i++) {
        pq->data[i] = pq->data[i + 1];
        pq->priority[i] = pq->priority[i + 1];
    }
    pq->size--;
    return item;
}

void display(PriorityQueue *pq) {
    if (isEmpty(pq)) {
        printf("Priority Queue is empty!\n");
        return;
    }
    printf("Priority Queue (value:priority): ");
    for (int i = 0; i < pq->size; i++) {
        printf("%d:%d ", pq->data[i], pq->priority[i]);
    }
    printf("\n");
}

int main() {
    PriorityQueue pq;
    initQueue(&pq);

    int choice, value, priority;
    do {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value and priority: ");
                scanf("%d %d", &value, &priority);
                enqueue(&pq, value, priority);
                break;
            case 2:
                printf("Dequeued: %d\n", dequeue(&pq));
                break;
            case 3:
                display(&pq);
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
