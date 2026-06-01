#include <stdio.h>
#include <stdlib.h>

int x[20];
int place(int k,int i){
    for(int j=1;j<k;j++){
        if(x[j]==i || (abs(k-j)==abs(i-x[j])))
            return 0;
    }
    return 1;
}

void nQueens(int k,int n){
    for(int i=1;i<=n;i++){
        if(place(k,i)){
            x[k]=i;
            if(k==n){
                    printf("\n");
                for(int j=1;j<=n;j++){
                    printf("\nRow: %d , Column: %d",j,x[j]);
                }

            }else nQueens(k+1,n);
        }
    }
}

int main(){
    int n;
    printf("Enter number of queens: ");
    scanf("%d",&n);
    nQueens(1,n);
    return 0;
}
