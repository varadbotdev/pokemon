#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define V 100 // Maximum number of vertices

// Function to find the vertex with the minimum key value
int minKey(int key[], bool mstSet[], int vertices) {
    int min = INT_MAX;
    int min_index = -1;

    for (int v = 0; v < vertices; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

// Recursive function to implement Prim's MST
void primMSTRecursive(int graph[V][V], int key[], bool mstSet[], int parent[], int vertices, int count) {
    if (count >= vertices - 1) {
        return; // Base case: MST is fully constructed
    }

    // Get the vertex with the minimum key value
    int u = minKey(key, mstSet, vertices);
    mstSet[u] = true;  // Mark the vertex as included in the MST

    // Update the key values and parent index for adjacent vertices
    for (int v = 0; v < vertices; v++) {
        if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
            parent[v] = u;
            key[v] = graph[u][v];
        }
    }

    // Recur for the next vertex
    primMSTRecursive(graph, key, mstSet, parent, vertices, count + 1);
}

// Function to print the MST
void printMST(int parent[], int graph[V][V], int vertices) {
    printf("Edge \tWeight\n");
    for (int i = 1; i < vertices; i++) {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
    }
}

// Function to implement Prim's MST algorithm
void primMST(int graph[V][V], int vertices) {
    int parent[V]; // Array to store the constructed MST
    int key[V];    // Key values used to pick the minimum weight edge
    bool mstSet[V]; // Boolean array to track vertices included in MST

    // Initialize all key values as INFINITE and mstSet[] as false
    for (int i = 0; i < vertices; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0; // Start with the first vertex
    parent[0] = -1; // The first vertex is always the root of MST

    // Call the recursive function to construct MST
    primMSTRecursive(graph, key, mstSet, parent, vertices, 0);

    // Print the constructed MST
    printMST(parent, graph, vertices);
}

int main() {
    int vertices;

    // Input the number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    int graph[V][V];

    // Input the adjacency matrix
    printf("Enter the adjacency matrix of the graph (use 0 for no direct edge):\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("Edge %d - %d: ", i, j);
            scanf("%d", &graph[i][j]);
        }
    }

    // Call Prim's MST algorithm
    primMST(graph, vertices);

    return 0;
}
