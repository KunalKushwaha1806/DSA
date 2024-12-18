#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    int priority;
    struct Node *next;
} Node;

typedef struct {
    Node *front;
} PriorityQueue;

void initQueue(PriorityQueue *pq) {
    pq->front = NULL;
}

int isEmpty(PriorityQueue *pq) {
    return pq->front == NULL;
}

void enqueue(PriorityQueue *pq, int value, int prio) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->priority = prio;
    newNode->next = NULL;

    if (pq->front == NULL || pq->front->priority > prio) {
        newNode->next = pq->front;
        pq->front = newNode;
    } else {
        Node *temp = pq->front;
        while (temp->next != NULL && temp->next->priority <= prio) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

int dequeue(PriorityQueue *pq) {
    if (isEmpty(pq)) {
        printf("Priority Queue is empty!\n");
        return -1;
    }
    Node *temp = pq->front;
    int item = temp->data;
    pq->front = pq->front->next;
    free(temp);
    return item;
}

void display(PriorityQueue *pq) {
    if (isEmpty(pq)) {
        printf("Priority Queue is empty!\n");
        return;
    }
    printf("Priority Queue (value:priority): ");
    Node *temp = pq->front;
    while (temp) {
        printf("%d:%d ", temp->data, temp->priority);
        temp = temp->next;
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
