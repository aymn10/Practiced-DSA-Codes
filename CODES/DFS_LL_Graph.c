// Q: Implement Depth First Search using linked representation of graph
// Time Complexity: O(V + E) 
// V = Number of vertices (nodes) in the graph
// E = Number of edges (connections) in the graph
// Space Complexity: O(V + E)

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int vertices;
    struct Node** adj;
};

struct Node* createNode(int v) {
    struct Node* newnode = malloc(sizeof(struct Node));
    newnode->vertex = v;
    newnode->next = NULL;
    return newnode;
}

struct Graph* createGraph(int v) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->vertices = v;
    graph->adj = malloc(v * sizeof(struct Node*));

    for (int i = 0; i < v; i++)
        graph->adj[i] = NULL;

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newnode = createNode(dest);
    newnode->next = graph->adj[src];
    graph->adj[src] = newnode;

    newnode = createNode(src);
    newnode->next = graph->adj[dest];
    graph->adj[dest] = newnode;
}

int visited[100];

void DFS(struct Graph* graph, int v) {
    visited[v] = 1;
    printf("%d ", v);

    struct Node* temp = graph->adj[v];
    while (temp != NULL) {
        if (!visited[temp->vertex])
            DFS(graph, temp->vertex);
        temp = temp->next;
    }
}

int main() {
    int v, e, src, dest, start;

    printf("Enter number of vertices: ");
    scanf("%d", &v);

    struct Graph* graph = createGraph(v);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    for (int i = 0; i < e; i++) {
        printf("Enter edge (src dest): ");
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    for (int i = 0; i < v; i++)
        visited[i] = 0;

    printf("Enter starting vertex for DFS: ");
    scanf("%d", &start);

    printf("DFS Traversal: ");
    DFS(graph, start);

    return 0;
}
