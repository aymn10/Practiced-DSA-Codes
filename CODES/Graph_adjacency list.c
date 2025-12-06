// Q: Insert and delete nodes in a graph using adjacency list
// Time Complexity: O(V + E) ; V is Number of vertices (nodes) in the graph || E is Number of edges (connections) in the graph
// Space Complexity: O(V + E); V linked lists (one for each vertex) || E nodes inside those lists (one for each edge)

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node** adjLists;
};

struct Node* createNode(int v) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjLists = malloc(vertices * sizeof(struct Node*));

    for (int i = 0; i < vertices; i++)
        graph->adjLists[i] = NULL;

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void deleteEdge(struct Graph* graph, int src, int dest) {
    struct Node* temp = graph->adjLists[src];
    struct Node* prev = NULL;

    while (temp != NULL && temp->vertex != dest) {
        prev = temp;
        temp = temp->next;
    }

    if (temp != NULL) {
        if (prev == NULL)
            graph->adjLists[src] = temp->next;
        else
            prev->next = temp->next;
        free(temp);
    }

    temp = graph->adjLists[dest];
    prev = NULL;

    while (temp != NULL && temp->vertex != src) {
        prev = temp;
        temp = temp->next;
    }

    if (temp != NULL) {
        if (prev == NULL)
            graph->adjLists[dest] = temp->next;
        else
            prev->next = temp->next;
        free(temp);
    }
}

void deleteNode(struct Graph* graph, int node) {
    graph->adjLists[node] = NULL;

    for (int i = 0; i < graph->numVertices; i++)
        deleteEdge(graph, i, node);
}

void display(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        struct Node* temp = graph->adjLists[i];
        printf("Vertex %d: ", i);
        while (temp != NULL) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int v, choice, src, dest, node;

    printf("Enter number of vertices: ");
    scanf("%d", &v);

    struct Graph* graph = createGraph(v);

    while (1) {
        printf("\nMenu\n");
        printf("1. Add Edge\n");
        printf("2. Delete Edge\n");
        printf("3. Delete Node\n");
        printf("4. Display Graph\n");
        printf("5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter src and dest: ");
            scanf("%d %d", &src, &dest);
            addEdge(graph, src, dest);
            break;

        case 2:
            printf("Enter src and dest: ");
            scanf("%d %d", &src, &dest);
            deleteEdge(graph, src, dest);
            break;

        case 3:
            printf("Enter node to delete: ");
            scanf("%d", &node);
            deleteNode(graph, node);
            break;

        case 4:
            display(graph);
            break;

        case 5:
            return 0;
        }
    }
}
