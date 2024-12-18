/*
Explanation of Floyd-Warshall Algorithm:
Graph Representation: The graph is represented as an adjacency matrix (graph[][]).
Distance Matrix: A dist[][] matrix is used where dist[i][j] represents the shortest distance from vertex i to vertex j.
Triple Nested Loops: The algorithm iterates through all possible pairs of vertices (i, j) and checks if any vertex k 
provides a shorter path between i and j.
All-Pairs Shortest Paths: The algorithm computes the shortest path for every pair of vertices.
*/
#include <stdio.h>
#include <limits.h>

#define MAX 100
#define INF INT_MAX

// Function to implement Floyd-Warshall Algorithm
void floydWarshall(int graph[MAX][MAX], int vertices) {
    int dist[MAX][MAX];

    // Initialize the distance matrix
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            if (graph[i][j] == 0 && i != j)
                dist[i][j] = INF;  // No direct path
            else
                dist[i][j] = graph[i][j];
        }
    }

    // Update the distance matrix by considering each vertex as an intermediate vertex
    for (int k = 0; k < vertices; k++) {
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the shortest distances
    printf("Shortest Paths between every pair of vertices:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            if (dist[i][j] == INF)
                printf("INF ");
            else
                printf("%d ", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int vertices = 4;
    int graph[4][4] = {
        {0, 3, INF, 7},
        {3, 0, 1, INF},
        {INF, 1, 0, 2},
        {7, INF, 2, 0}
    };

    printf("Shortest Path using Floyd-Warshall’s Algorithm:\n");
    floydWarshall(graph, vertices);
    return 0;
}


