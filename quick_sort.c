#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int partition(int low,int high,int arr[]){
    int i=low;
    int j=high+1;
    int pivot=arr[low];
    while(i<j){
        do{
            i++;
        }while(i<=high && arr[i]<=pivot);
        do{
            j--;
        }while(arr[j]>pivot);
        if(i<j){
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
   int temp2 = arr[j];
   arr[j]=pivot;
   arr[low]=temp2;
   return j;
}

void quickSort(int low,int high,int arr[]){
    if(low<high){
        int p=partition(low,high,arr);
        quickSort(low,p-1,arr);
        quickSort(p+1,high,arr);
    }
}

int main() {
    int n = 75000;
    int arr[n];

    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % (2 * n);
    }

    clock_t start, end;
    double cpu_time;

    start = clock();

    quickSort(0, n - 1, arr);

    end = clock();

    cpu_time = ((double)(end - start) / CLOCKS_PER_SEC) * 1000.0;

    printf("Time taken = %.3f milliseconds\n", cpu_time);

    return 0;
}

