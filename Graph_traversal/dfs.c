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

// Function prototypes
Node* createNode(int);
Graph* createGraph(int);
void addEdge(Graph*, int, int);
void dfs(Graph*, int);
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

// Depth-First Search (DFS)
void dfs(Graph* graph, int vertex) {
    graph->visited[vertex] = 1;
    printf("%d ", vertex);

    Node* temp = graph->adjLists[vertex];
    while (temp) {
        int adjVertex = temp->vertex;

        if (!graph->visited[adjVertex]) {
            dfs(graph, adjVertex);
        }
        temp = temp->next;
    }
}

// Reset visited array for multiple traversals
void resetVisited(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        graph->visited[i] = 0;
    }
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

    int startVertex = 0; // Starting vertex for DFS
    printf("Graph created. Performing DFS starting from vertex %d:\n", startVertex);
    dfs(graph, startVertex);

    return 0;
}
