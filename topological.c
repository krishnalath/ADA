#include <stdio.h>

int main() {
    int n,count;
    printf("Enter number of vertices: ");
    scanf("%d",&n);
    int graph[n][n],indegree[n];
    for(int i=0;i<n;i++)
        indegree[i]=0;
        
    printf("Enter adjacency matrix: ");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&graph[i][j]);
            if(graph[i][j])
                indegree[j]++;
        }
    }
    int queue[100],front=0,rear=0;
    printf("TOPOLOGICAL SORTING: \n");
    for(int i=0;i<n;i++){
        if(indegree[i]==0)
            queue[rear++]=i;
    }
    
    while(front<rear){
        int u=queue[front++];
        printf("%d ",u);
        count++;
        for(int v=0;v<n;v++){
            if(graph[u][v]){
                indegree[v]--;
                if(indegree[v]==0)
                    queue[rear++]=v;
            }}
    }
    if(count!=n)
        printf("is not possible for cyclic graph");

    return 0;
}
