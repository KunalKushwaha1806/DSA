#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Maximum number of vertices

// Structure for adjacency list node
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Structure for adjacency list
typedef struct Graph {
    int numVertices;
    Node* adjLists[MAX];
    int visited[MAX];
} Graph;

// Queue structure for BFS
typedef struct Queue {
    int items[MAX];
    int front, rear;
} Queue;

// Function prototypes
Node* createNode(int);
Graph* createGraph(int);
void addEdge(Graph*, int, int);
void bfs(Graph*, int);
Queue* createQueue();
void enqueue(Queue*, int);
int dequeue(Queue*);
int isQueueEmpty(Queue*);
void resetVisited(Graph*);

// Create a new node
Node* createNode(int vertex) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Create a graph with n vertices
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0; // Mark all vertices as unvisited initially
    }

    return graph;
}

// Add an edge to the graph (undirected graph)
void addEdge(Graph* graph, int src, int dest) {
    // Add edge from src to dest
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add edge from dest to src (since it's undirected)
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Breadth-First Search (BFS)
void bfs(Graph* graph, int startVertex) {
    Queue* queue = createQueue();

    printf("BFS Traversal: ");
    graph->visited[startVertex] = 1;
    enqueue(queue, startVertex);

    while (!isQueueEmpty(queue)) {
        int currentVertex = dequeue(queue);
        printf("%d ", currentVertex);

        Node* temp = graph->adjLists[currentVertex];
        while (temp) {
            int adjVertex = temp->vertex;

            if (!graph->visited[adjVertex]) {
                graph->visited[adjVertex] = 1;
                enqueue(queue, adjVertex);
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

// Reset visited array for multiple traversals
void resetVisited(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        graph->visited[i] = 0;
    }
}

// Create a queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Enqueue an element
void enqueue(Queue* q, int value) {
    if (q->rear == MAX - 1) {
        printf("Queue is full!\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
}

// Dequeue an element
int dequeue(Queue* q) {
    if (q->front == -1) {
        printf("Queue is empty!\n");
        return -1;
    }
    int item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
    return item;
}

// Check if the queue is empty
int isQueueEmpty(Queue* q) {
    return q->front == -1;
}

// Main function with predefined inputs
int main() {
    int vertices = 6;  // Number of vertices in the graph
    int edges = 7;     // Number of edges in the graph
    int src, dest;

    // Create a graph with 6 vertices
    Graph* graph = createGraph(vertices);

    // Add edges to the graph (undirected)
    int edgesData[7][2] = {
        {0, 1}, {0, 2}, {1, 3}, {1, 4},
        {2, 5}, {3, 4}, {4, 5}
    };

    for (int i = 0; i < edges; i++) {
        src = edgesData[i][0];
        dest = edgesData[i][1];
        addEdge(graph, src, dest);
    }

    int startVertex = 0; // Starting vertex for BFS
    printf("Graph created. Performing BFS starting from vertex %d:\n", startVertex);
    bfs(graph, startVertex);

    return 0;
}
