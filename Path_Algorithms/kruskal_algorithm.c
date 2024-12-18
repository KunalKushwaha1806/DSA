#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

#define MAX 100

// Structure to represent an edge
typedef struct {
    int src, dest, weight;
} Edge;

// Function to compare two edges by their weight
int compareEdges(const void *a, const void *b) {
    return ((Edge*)a)->weight - ((Edge*)b)->weight;
}

// Function to find the parent of a vertex (for Union-Find)
int find(int parent[], int i) {
    if (parent[i] == i)
        return i;
    return find(parent, parent[i]); // Path compression
}

// Function to perform the union of two sets
void unionSets(int parent[], int rank[], int x, int y) {
    int rootX = find(parent, x);
    int rootY = find(parent, y);

    if (rootX != rootY) {
        if (rank[rootX] < rank[rootY])
            parent[rootX] = rootY;
        else if (rank[rootX] > rank[rootY])
            parent[rootY] = rootX;
        else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
}

// Function to implement Kruskal's algorithm
void kruskal(Edge edges[], int vertices, int edgeCount) {
    int parent[MAX], rank[MAX];

    // Initialize parent and rank arrays
    for (int i = 0; i < vertices; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    // Sort edges by weight
    qsort(edges, edgeCount, sizeof(Edge), compareEdges);

    printf("Minimum Spanning Tree (Kruskal's Algorithm):\n");

    for (int i = 0; i < edgeCount; i++) {
        int x = find(parent, edges[i].src);
        int y = find(parent, edges[i].dest);

        // If including this edge doesn't form a cycle
        if (x != y) {
            printf("%d - %d   %d\n", edges[i].src, edges[i].dest, edges[i].weight);
            unionSets(parent, rank, x, y);
        }
    }
}

int main() {
    int vertices = 5;
    Edge edges[] = {
        {0, 1, 2},
        {0, 3, 6},
        {1, 2, 3},
        {1, 3, 8},
        {1, 4, 5},
        {2, 4, 7},
        {3, 4, 9}
    };
    int edgeCount = sizeof(edges) / sizeof(edges[0]);

    kruskal(edges, vertices, edgeCount);
    return 0;
}
