#include <stdio.h>
int getMobile(int p[],int d[],int n){
    int mobile=0;
    int mobilePos=-1;
    for(int i=0;i<n;i++){
        if(d[i]==-1 && i!=0){
            if(p[i]>p[i-1] && p[i]>mobile){
                mobile=p[i];
                mobilePos=i;
            }
        }
        if(d[i]==1 && i!=n-1){
            if(p[i]>p[i+1] && p[i]>mobile){
                mobile=p[i];
                mobilePos=i;
            }
        }
    }
    return mobilePos;
}
int main() {
    int n;
    printf("Enter number of digits: ");
    scanf("%d",&n);
    int p[n],d[n];
    for(int i=0;i<n;i++){
        p[i]=i+1;
        d[i]=-1;
    }
    while(1){
        for(int i=0;i<n;i++)
            printf("%d",p[i]);
        printf("\n");
        int pos = getMobile(p,d,n);
        if(pos==-1) break;
        int swapPos;
        if(d[pos]==-1)
            swapPos=pos-1;
        if(d[pos]==1)
            swapPos=pos+1;
        int temp=d[pos];
        d[pos]=d[swapPos];
        d[swapPos]=temp;
        temp=p[pos];
        p[pos]=p[swapPos];
        p[swapPos]=temp;
        pos=swapPos;
        for(int i=0;i<n;i++){
            if(p[i]>p[pos])
                d[i]=-d[i];
        }
    }
    return 0;
}
