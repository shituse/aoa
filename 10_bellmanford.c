#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Edge {
    int src, dest, weight;
};

struct Graph {
    int V, E;
    struct Edge* edge;
};

struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (struct Edge*)malloc(E * sizeof(struct Edge));
    return graph;
}

void printSolution(int dist[], int pred[], int n) {
    printf("Vertex   Distance from Source   Path\n");
    for (int i = 0; i < n; ++i) {
        printf("%d \t\t %d \t\t ", i, dist[i]);
        int j = i;
        while (j != -1) {
            printf("%d ", j);
            j = pred[j];
            if (j != -1)
                printf("-> ");
        }
        printf("\n");
    }
}

void BellmanFord(struct Graph* graph, int src) {
    int V = graph->V;
    int E = graph->E;
    int dist[V];
    int pred[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        pred[i] = -1;
    }
    dist[src] = 0;

    for (int i = 0; i < V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int weight = graph->edge[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pred[v] = u;
            }
        }
    }

    // Check for negative weight cycles
    for (int i = 0; i < E; i++) {
        int u = graph->edge[i].src;
        int v = graph->edge[i].dest;
        int weight = graph->edge[i].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            printf("Graph contains negative weight cycle\n");
            return;
        }
    }

    printSolution(dist, pred, V);
}

int main() {
    int V, E;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("Enter the number of edges: ");
    scanf("%d", &E);

    struct Graph* graph = createGraph(V, E);

    printf("Enter edge (src, dest, weight):\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &graph->edge[i].src, &graph->edge[i].dest, &graph->edge[i].weight);
    }

    int src;
    printf("Enter the source vertex: ");
    scanf("%d", &src);

    BellmanFord(graph, src);

    return 0;
}