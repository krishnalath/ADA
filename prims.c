#include <stdio.h>
#include <limits.h>
int main() {
    int n;
    printf("Enter number of vertices: ");
    scanf("%d",&n);
    int cost[n][n],visited[n];
    printf("Enter adj matrix: ");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&cost[i][j])
            if(i!=j && cost[i][j]==0)
                cost[i][j]=INT_MAX;
        }
    }
    
    for(int i=0;i<n;i++)
        visited[i]=0;
        
    visited[0]=1;
    int edges = 0;
    int minCost=0;
    printf("Edges in MST: \n");
    while(edges<n-1){
        int min=INT_MAX;
        int u=-1,v=-1;
        for(int i=0;i<n;i++){
            if(visited[i]){
                for(int j=0;j<n;j++){
                    if(!visited[j] && cost[i][j]<min){
                        min = cost[i][j];
                        u=i;
                        v=j;
                    }
                }
            }
        }
        if (u == -1 || v == -1) {
            printf("Graph is disconnected.\n");
            return 0;
        }
        
        printf("%d -> %d = %d\n",u,v,min);
        minCost+=min;
        visited[v]=1;
        edges++;
    }
    printf("Minimum cost is %d: ",minCost);
    return 0;
}
