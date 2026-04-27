#include <stdio.h>
#include <limits.h>

// Function to print path recursively
void printPath(int parent[], int j) {
    if(parent[j] == j)
        return;
    printPath(parent, parent[j]);
    printf(" -> %d", j);
}

int main() {
    int n;
    printf("Enter number of vertices : ");
    scanf("%d", &n);

    int a[n][n];
    printf("Enter adjacency matrix:\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &a[i][j]);
        }
    }

    int distance[n], visited[n], parent[n];
    int source;

    printf("Enter source vertex : ");
    scanf("%d", &source);

    // Initialization
    for(int i = 0; i < n; i++){
        if(i == source)
            distance[i] = 0;
        else if(a[source][i] != 0)
            distance[i] = a[source][i];
        else
            distance[i] = INT_MAX;

        parent[i] = source;
        visited[i] = 0;
    }

    parent[source] = source;
    visited[source] = 1;

    // Dijkstra's algorithm
    for(int i = 1; i < n; i++){
        int min = INT_MAX, u = -1;

        for(int j = 0; j < n; j++){
            if(!visited[j] && distance[j] < min){
                min = distance[j];
                u = j;
            }
        }

        if(u == -1) break;

        visited[u] = 1;

        for(int v = 0; v < n; v++){
            if(a[u][v] != 0 && !visited[v] && distance[u] != INT_MAX){
                if(distance[u] + a[u][v] < distance[v]){
                    distance[v] = distance[u] + a[u][v];
                    parent[v] = u;
                }
            }
        }
    }

    // Output with paths
    printf("Shortest paths from %d:\n", source);
    for(int i = 0; i < n; i++){
        if(distance[i] == INT_MAX){
            printf("%d -> %d : No path\n", source, i);
        } else {
            printf("%d", source);
            printPath(parent, i);
            printf(" : %d\n", distance[i]);
        }
    }

    return 0;
}