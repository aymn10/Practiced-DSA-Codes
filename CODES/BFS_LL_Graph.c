// Q: Implement Breadth First Search (BFS) using linked list representation of a graph
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

struct Queue {
    int arr[100];
    int front, rear;
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

struct Queue* createQueue() {
    struct Queue* q = malloc(sizeof(struct Queue));
    q->front = q->rear = -1;
    return q;
}

void enqueue(struct Queue* q, int v) {
    if (q->rear == -1)
        q->front = q->rear = 0;
    else
        q->rear++;
    q->arr[q->rear] = v;
}

int dequeue(struct Queue* q) {
    if (q->front == -1 || q->front > q->rear)
        return -1;
    return q->arr[q->front++];
}

int isEmpty(struct Queue* q) {
    return q->front == -1 || q->front > q->rear;
}

void BFS(struct Graph* graph, int start) {
    int visited[100];
    for (int i = 0; i < graph->vertices; i++)
        visited[i] = 0;

    struct Queue* q = createQueue();
    visited[start] = 1;
    enqueue(q, start);

    while (!isEmpty(q)) {
        int v = dequeue(q);
        printf("%d ", v);

        struct Node* temp = graph->adj[v];
        while (temp != NULL) {
            int adj = temp->vertex;
            if (!visited[adj]) {
                visited[adj] = 1;
                enqueue(q, adj);
            }
            temp = temp->next;
        }
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

    printf("Enter starting vertex for BFS: ");
    scanf("%d", &start);

    printf("BFS Traversal: ");
    BFS(graph, start);

    return 0;
}
