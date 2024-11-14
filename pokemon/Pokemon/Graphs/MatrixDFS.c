#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100 // Maximum number of vertices

// Function to perform DFS traversal
void DFS(int graph[MAX_VERTICES][MAX_VERTICES], int vertex, bool visited[], int vertices) {
    // Mark the current vertex as visited
    visited[vertex] = true;
    printf("%d ", vertex); // Print the visited vertex

    // Explore all the adjacent vertices
    for (int i = 0; i < vertices; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) { // If there is an edge and the vertex is not visited
            DFS(graph, i, visited, vertices); // Recursively call DFS on the unvisited neighbor
        }
    }
}

// Function to create the graph by user input
void createGraph(int graph[MAX_VERTICES][MAX_VERTICES], int vertices) {
    int u, v;
    printf("Enter the edges of the graph (u, v) where u and v are vertex indices (0 to %d):\n", vertices - 1);
    printf("Enter -1 -1 to stop.\n");

    // Initialize the adjacency matrix with 0 (no edge)
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph[i][j] = 0;
        }
    }

    while (1) {
        printf("Enter edge (u v): ");
        scanf("%d %d", &u, &v);

        if (u == -1 && v == -1) {
            break;
        }

        if (u >= 0 && u < vertices && v >= 0 && v < vertices) {
            graph[u][v] = 1; // Add edge from u to v
            graph[v][u] = 1; // For undirected graph, add edge from v to u
        } else {
            printf("Invalid vertices! Please enter valid vertices within the range 0 to %d.\n", vertices - 1);
        }
    }
}

int main() {
    int vertices;
    int graph[MAX_VERTICES][MAX_VERTICES];

    // Input the number of vertices
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &vertices);

    if (vertices > MAX_VERTICES) {
        printf("Exceeded maximum number of vertices!\n");
        return -1;
    }

    // Create the graph by taking user input
    createGraph(graph, vertices);

    int startVertex;
    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &startVertex);

    // Create a visited array to keep track of visited vertices
    bool visited[MAX_VERTICES] = {false};

    // Perform DFS traversal from the start vertex
    printf("DFS Traversal starting from vertex %d: ", startVertex);
    DFS(graph, startVertex, visited, vertices);
    printf("\n");

    return 0;
}
