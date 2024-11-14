#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100 // Maximum number of vertices

// Function to perform BFS traversal
void BFS(int graph[MAX_VERTICES][MAX_VERTICES], int vertices, int start) {
    // Array to keep track of visited vertices
    bool visited[MAX_VERTICES] = {false};

    // Queue for BFS
    int queue[MAX_VERTICES];
    int front = -1, rear = -1;

    // Start by marking the start vertex as visited
    visited[start] = true;
    queue[++rear] = start;  // Enqueue the start vertex

    printf("BFS Traversal starting from vertex %d: ", start);

    while (front != rear) {
        // Dequeue a vertex from the queue
        int currentVertex = queue[++front];

        // Print the dequeued vertex
        printf("%d ", currentVertex);

        // Explore all the neighbors of the dequeued vertex
        for (int i = 0; i < vertices; i++) {
            // If there's an edge and the vertex is not visited
            if (graph[currentVertex][i] != 0 && !visited[i]) {
                visited[i] = true;      // Mark the vertex as visited
                queue[++rear] = i;      // Enqueue the vertex
            }
        }
    }
    printf("\n");
}

// Function to create the graph using an adjacency matrix
void createGraph(int graph[MAX_VERTICES][MAX_VERTICES], int vertices) {
    int u, v;
    printf("Enter the edges of the graph (u, v) where u and v are vertex indices (0 to %d):\n", vertices-1);
    printf("Enter -1 -1 to stop.\n");

    while (1) {
        printf("Enter edge (u v): ");
        scanf("%d %d", &u, &v);

        if (u == -1 && v == -1)
            break;

        if (u >= 0 && u < vertices && v >= 0 && v < vertices) {
            graph[u][v] = 1; // Directed graph, edge from u to v
            graph[v][u] = 1; // For undirected graph, add the reverse edge as well
        } else {
            printf("Invalid vertices! Please enter valid vertices within the range 0 to %d.\n", vertices-1);
        }
    }
}

int main() {
    int vertices;
    int graph[MAX_VERTICES][MAX_VERTICES] = {0}; // Initialize the graph as empty (0s)

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &vertices);

    if (vertices > MAX_VERTICES) {
        printf("Exceeded maximum number of vertices!\n");
        return -1;
    }

    // Create the graph
    createGraph(graph, vertices);

    int startVertex;
    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &startVertex);

    // Perform BFS traversal from the start vertex
    BFS(graph, vertices, startVertex);

    return 0;
}
