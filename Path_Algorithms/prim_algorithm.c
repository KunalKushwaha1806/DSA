#include <stdio.h>
#include <limits.h>
#include <stdbool.h>  // Include this header to use 'bool'

#define MAX 100

// Function to find the vertex with the minimum key value
int minKey(int key[], bool mstSet[], int vertices) {
    int min = INT_MAX, minIndex;
    for (int v = 0; v < vertices; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

// Function to implement Prim's algorithm
void prim(int graph[MAX][MAX], int vertices) {
    int parent[MAX]; // Array to store the MST
    int key[MAX];     // Key values used to pick the minimum weight edge
    bool mstSet[MAX]; // To represent the vertices included in the MST

    // Initialize all keys as INFINITE and mstSet[] as false
    for (int i = 0; i < vertices; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[0] = 0; // Start with vertex 0
    parent[0] = -1; // First node is the root

    // Find the MST
    for (int count = 0; count < vertices - 1; count++) {
        int u = minKey(key, mstSet, vertices);
        mstSet[u] = 1;

        for (int v = 0; v < vertices; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the MST
    printf("Edge   Weight\n");
    for (int i = 1; i < vertices; i++) {
        printf("%d - %d    %d\n", parent[i], i, graph[i][parent[i]]);
    }
}

int main() {
    int vertices = 5;
    int graph[5][5] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    printf("Minimum Spanning Tree (Prim's Algorithm):\n");
    prim(graph, vertices);
    return 0;
}
