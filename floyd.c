// Online C compiler to run C program online
#include <stdio.h>
#include <limits.h>
int main() {
    int n;
    printf("Enter numebr of vertices: ");
    scanf("%d",&n);
    int a[n][n];
    printf("Enter adj matrix: ");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
            if(i!=j && a[i][j]==0)
                a[i][j] = INT_MAX;
        }
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(a[i][k]!=INT_MAX && a[k][j]!=INT_MAX){
                    if(a[i][k]+a[k][j]<a[i][j])
                        a[i][j]=a[i][k]+a[k][j];
                }
            }
        }
    }
    printf("Shortest Path: \n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j] == INT_MAX)
                printf("INF\t");
            else
                printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
}
