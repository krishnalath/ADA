#include <stdio.h>

int lomutoPartition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int s = low;

    for(int i = low+1; i <= high; i++)
    {
        if(arr[i] < pivot)
        {
            s++;

            int temp = arr[s];
            arr[s] = arr[i];
            arr[i] = temp;
        }
    }

    int temp = arr[low];
    arr[low] = arr[s];
    arr[s] = temp;

    return s;
}

int quickSelect(int arr[], int low, int high, int k)
{
    int s = lomutoPartition(arr, low, high);

    if(s == k-1)
        return arr[s];

    else if(s > k-1)
        return quickSelect(arr, low, s-1, k);

    else
        return quickSelect(arr, s+1, high, k);
}

int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d",&n);

    int arr[n];

    printf("Enter elements: ");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    int k;

    printf("Enter k: ");
    scanf("%d",&k);

    int ans = quickSelect(arr,0,n-1,k);

    printf("%d-th smallest element = %d",k,ans);

    return 0;
}
