// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>
int pos[20],count=0;
int isSafe(int row,int col){
    for(int i=0;i<row;i++){
        if(pos[i]==col || abs(pos[i]-col)==abs(i-row))
            return 0;
    }
    return 1;
}
void solve(int row,int n){
    if(row==n){
        count++;
        printf("Solution %d\n",count);
        for(int i=0;i<n;i++)
            printf("Row %d -> Col %d\n",i+1,pos[i]+1);
        return;
    }
    for(int col=0;col<n;col++){
        if(isSafe(row,col)){
            pos[row]=col;
            solve(row+1,n);
        }
    }
}
int main() {
    int n;
    printf("Nummber of queens: ");
    scanf("%d",&n);
    solve(0,n);
    if(count == 0)
        printf("No solution");
    return 0;
}
