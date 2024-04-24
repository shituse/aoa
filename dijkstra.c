#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define V 4

int minDistance(int dist[], bool sptSet[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        if (sptSet[v] == false && dist[v] < min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void printD(int dist[]) 
{
    printf("D (Distance) Matrix:\n");
    for (int i = 0; i < V; i++) {
        printf("%d ", dist[i]);
    }
    printf("\n");
}

void printPi(int pi[]) 
{
    printf("Pi (Predecessor) Matrix:\n");
    for (int i = 0; i < V; i++) {
        printf("%d ", pi[i]);
    }
    printf("\n");
}

void printPath(int pi[], int j, int src) 
{
    if (j == src) {
        printf("%d ", src);
        return;
    }
    printPath(pi, pi[j], src);
    printf("%d ", j);
}

void printAllPaths(int pi[], int src) 
{
    printf("\nShortest Paths from vertex %d:\n", src);
    for (int i = 0; i < V; i++) {
        if (i != src) {
            printf("Path to vertex %d: ", i);
            printPath(pi, i, src);
            printf("\n");
        }
    }
}

void dijkstra(int graph[V][V], int src) 
{
    int dist[V];    //key
    bool sptSet[V];     //mstSet
    int pi[V];  //pi matrix sake

    for (int i = 0; i < V; i++) 
    {
        dist[i] = INT_MAX;  //just like key[i]
        sptSet[i] = false;  //like mstSet[i]
        pi[i] = -1; // Initialize all predecessors to -1
    }
    
    dist[src] = 0;  //instead of key[0] here dist[src]
    
    for (int count = 0; count < V - 1; count++) {

        int u = minDistance(dist, sptSet); //minKey
        sptSet[u] = true;
        
        for (int v = 0; v < V; v++) 
        {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) 
            {
                dist[v] = dist[u] + graph[u][v];
                pi[v] = u; // Update predecessor
            }
        }
    }
    
    printD(dist);
    printPi(pi);
    printAllPaths(pi, src);
}

int main() {
    int graph[V][V];

    printf("Enter the adjacency matrix of the graph (%d x %d):\n", V, V);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int source;
    printf("Enter the source vertex: ");
    scanf("%d", &source);

    dijkstra(graph, source);

    return 0;
}
