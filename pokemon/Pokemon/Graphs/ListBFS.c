#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100 // Maximum number of vertices

// Define the structure for the adjacency list node
struct Node {
    int vertex;
    struct Node* next;
};

// Define the structure for the graph
struct Graph {
    struct Node* adjList[MAX_VERTICES];
    int vertices;
};

// Function to create a new adjacency list node
struct Node* createNode(int vertex) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize a graph
void initializeGraph(struct Graph* graph, int vertices) {
    graph->vertices = vertices;
    for (int i = 0; i < vertices; i++) {
        graph->adjList[i] = NULL; // Initialize each adjacency list as empty
    }
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int u, int v) {
    // Add edge from u to v
    struct Node* newNode = createNode(v);
    newNode->next = graph->adjList[u];
    graph->adjList[u] = newNode;

    // For undirected graph, add edge from v to u
    newNode = createNode(u);
    newNode->next = graph->adjList[v];
    graph->adjList[v] = newNode;
}

// Function to perform BFS traversal
void BFS(struct Graph* graph, int start) {
    bool visited[MAX_VERTICES] = {false};
    int queue[MAX_VERTICES];
    int front = -1, rear = -1;

    // Mark the start vertex as visited and enqueue it
    visited[start] = true;
    queue[++rear] = start;
    
    printf("BFS Traversal starting from vertex %d: ", start);

    while (front != rear) {
        // Dequeue a vertex from the queue
        int currentVertex = queue[++front];

        // Print the current vertex
        printf("%d ", currentVertex);

        // Traverse all adjacent vertices of the current vertex
        struct Node* adjList = graph->adjList[currentVertex];
        while (adjList != NULL) {
            int adjVertex = adjList->vertex;
            if (!visited[adjVertex]) {
                visited[adjVertex] = true;  // Mark the vertex as visited
                queue[++rear] = adjVertex;  // Enqueue the adjacent vertex
            }
            adjList = adjList->next;  // Move to the next adjacent vertex
        }
    }
    printf("\n");
}

// Function to create the graph using user input
void createGraph(struct Graph* graph, int vertices) {
    int u, v;
    printf("Enter the edges of the graph (u, v) where u and v are vertex indices (0 to %d):\n", vertices - 1);
    printf("Enter -1 -1 to stop.\n");

    while (1) {
        printf("Enter edge (u v): ");
        scanf("%d %d", &u, &v);

        if (u == -1 && v == -1) {
            break;
        }

        if (u >= 0 && u < vertices && v >= 0 && v < vertices) {
            addEdge(graph, u, v);  // Add edge to the graph
        } else {
            printf("Invalid vertices! Please enter valid vertices within the range 0 to %d.\n", vertices - 1);
        }
    }
}

int main() {
    int vertices;
    struct Graph graph;

    // Input the number of vertices
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &vertices);

    if (vertices > MAX_VERTICES) {
        printf("Exceeded maximum number of vertices!\n");
        return -1;
    }

    // Initialize the graph
    initializeGraph(&graph, vertices);

    // Create the graph by taking user input
    createGraph(&graph, vertices);

    int startVertex;
    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &startVertex);

    // Perform BFS traversal from the start vertex
    BFS(&graph, startVertex);

    return 0;
}
