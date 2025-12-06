// Q: Implement Dijkstra's shortest path algorithm for a directed graph
// Time Complexity: O(V^2) V = Number of vertices (nodes) in the graph
// Space Complexity: O(V)
/* Enter number of vertices: 5
Enter adjacency matrix:
0 10 0 30 100
0 0 50 0 0
0 0 0 0 10
0 0 20 0 60
0 0 0 0 0
Enter starting node: 0
*/

#include <stdio.h>

#define INF 9999
#define MAX 20

void dijkstra(int graph[MAX][MAX], int n, int start) {
    int cost[MAX][MAX], distance[MAX], visited[MAX], pred[MAX];
    int count, mindist, next;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cost[i][j] = graph[i][j] == 0 ? INF : graph[i][j];

    for (int i = 0; i < n; i++) {
        distance[i] = cost[start][i];
        pred[i] = start;
        visited[i] = 0;
    }

    distance[start] = 0;
    visited[start] = 1;
    count = 1;

    while (count < n - 1) {
        mindist = INF;
        for (int i = 0; i < n; i++)
            if (!visited[i] && distance[i] < mindist) {
                mindist = distance[i];
                next = i;
            }

        visited[next] = 1;
        for (int i = 0; i < n; i++)
            if (!visited[i] && mindist + cost[next][i] < distance[i]) {
                distance[i] = mindist + cost[next][i];
                pred[i] = next;
            }

        count++;
    }

    printf("Shortest distances from node %d:\n", start);
    for (int i = 0; i < n; i++)
        printf("%d --> %d = %d\n", start, i, distance[i]);
}

int main() {
    int n, start;
    int graph[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (0 for no edge):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter starting node: ");
    scanf("%d", &start);

    dijkstra(graph, n, start);

    return 0;
}
