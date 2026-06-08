#include <stdio.h>

int arr[20],x[20];
void subsetSum(int k,int n,int sum,int target){
    if(sum==target){
        for(int i=0;i<k;i++){
            if(x[i])
                printf("%d ",arr[i]);
        }
        printf("\n");
        return;
    }
    if(k==n || sum>target) return;
    
    x[k]=1;
    subsetSum(k+1,n,sum+arr[k],target);
    x[k]=0;
    subsetSum(k+1,n,sum,target);
}

int main() {
    int n,target;
    printf("Number of elements: ");
    scanf("%d",&n);
    printf("Enter elements: ");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    printf("Enter target: ");
    scanf("%d",&target);
    subsetSum(0,n,0,target);

    return 0;
}
