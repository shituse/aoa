#include <stdio.h>
#include <limits.h>

#define V 4

void printMatrix(int matrix[V][V], char *name) {
    printf("%s:\n", name);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (matrix[i][j] == INT_MAX) {
                printf("INF\t");
            } else {
                printf("%d\t", matrix[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

void printPath(int path[V][V], int u, int v) {
    if (path[u][v] == -1) {
        printf("No path from %d to %d\n", u, v);
        return;
    }
    printf("Shortest path from %d to %d: %d", u, v, u);
    while (u != v) {
        u = path[u][v];
        printf(" -> %d", u);
    }
    printf("\n");
}

void floydWarshall(int graph[V][V]) {
    int dist[V][V], path[V][V];

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
            if (i != j && graph[i][j] != INT_MAX) {
                path[i][j] = i;
            } else {
                path[i][j] = -1;
            }
        }
    }

    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    path[i][j] = path[k][j];
                }
            }
        }
    }

    printMatrix(dist, "D (Distance) Matrix");
    printMatrix(path, "Pi (Predecessor) Matrix");

    printf("Shortest paths between every pair of vertices:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (i != j) {
                printPath(path, i, j);
            }
        }
    }
}

int main() {
    int graph[V][V];

    printf("Enter the adjacency matrix of the graph (%d x %d):\n", V, V);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 0 && i != j) {
                graph[i][j] = INT_MAX;
            }
        }
    }

    floydWarshall(graph);

    return 0;
}
