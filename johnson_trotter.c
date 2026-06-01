#include <stdio.h>

int mobile(int p[],int d[],int n){
    int m=-1;
    for(int i=0;i<n;i++){
        if(d[i]==-1 && i>0 && p[i]>p[i-1] && p[i]>m)
            m=p[i];
        if(d[i]==1 && i<n-1 && p[i]>p[i+1] && p[i]>m)
            m=p[i];
    }
    return m;
}

int main(){
    int n;
    printf("Enter n: ");
    scanf("%d",&n);
    int p[n],d[n];
    for(int i=0;i<n;i++){
        d[i]=-1;
        p[i]=i+1;
    }
    while(1){
        for(int i=0;i<n;i++)
            printf("%d",p[i]);
        printf("\n");
        int m=mobile(p,d,n);
        if(m==-1) break;
        int pos;
        for(int i=0;i<n;i++){
            if(p[i]==m)
                pos = i;
        }
        int next = pos+d[pos];
        int temp = p[pos];
        p[pos]=p[next];
        p[next]=temp;
        temp=d[pos];
        d[pos]=d[next];
        d[next]=temp;

        for(int i=0;i<n;i++){
            if(p[i]>m)
                d[i]=-d[i];
        }
    }
    return 0;
}
