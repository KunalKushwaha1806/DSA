#include <stdio.h>
#include <limits.h>
#include <stdbool.h>  // For using bool type

#define MAX 100
#define INF INT_MAX

// Function to find the vertex with the minimum distance value
int minDistance(int dist[], bool sptSet[], int vertices) {
    int min = INF, minIndex;
    for (int v = 0; v < vertices; v++) {
        if (!sptSet[v] && dist[v] < min) {
            min = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}

// Function to implement Dijkstra’s algorithm
void dijkstra(int graph[MAX][MAX], int src, int vertices) {
    int dist[MAX];  // The output array, dist[i] stores the shortest distance from src to i
    bool sptSet[MAX];  // sptSet[i] will be true if vertex i is included in the shortest path tree

    // Initialize all distances as INFINITE and sptSet[] as false
    for (int i = 0; i < vertices; i++) {
        dist[i] = INF;
        sptSet[i] = 0;
    }
    dist[src] = 0;  // Distance of source vertex from itself is always 0

    // Find the shortest path for all vertices
    for (int count = 0; count < vertices - 1; count++) {
        int u = minDistance(dist, sptSet, vertices);
        sptSet[u] = 1;

        for (int v = 0; v < vertices; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print the computed shortest distances
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < vertices; i++) {
        if (dist[i] == INF) {
            printf("%d \t INF\n", i);
        } else {
            printf("%d \t %d\n", i, dist[i]);
        }
    }
}

int main() {
    int vertices = 5;  // Number of vertices in the graph
    int graph[5][5] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };
    int source = 0;  // Starting from vertex 0

    printf("Shortest Path using Dijkstra’s Algorithm:\n");
    dijkstra(graph, source, vertices);
    return 0;
}
