#include <stdio.h>
#include <time.h>
#include <stdbool.h>

void heapify(int H[], int n) {

    for (int i = n / 2; i >= 1; i--) {

        int v = H[i];
        int k = i;
        bool heap = false;

        while (!heap && 2 * k <= n) {

            int j = 2 * k;
            if (j < n && H[j] < H[j + 1])
                j = j + 1;

            if (v >= H[j])
                heap = true;
            else {
                H[k] = H[j];
                k = j;
            }
        }

        H[k] = v;
    }
}

void heapsort(int H[], int n) {

    heapify(H, n);

    for (int i = n; i >= 2; i--) {
        int temp = H[1];
        H[1] = H[i];
        H[i] = temp;
        heapify(H, i - 1);
    }
}

int main() {

    int n;

    printf("Enter no. of elements: ");
    scanf("%d", &n);

    int H[n + 1];

    printf("Enter the elements:\n");

    for (int i = 1; i <= n; i++)
        scanf("%d", &H[i]);

    clock_t start, end;

    start = clock();

    heapsort(H, n);

    end = clock();

    double cpu_time_used =
        (((double)(end - start)) / CLOCKS_PER_SEC) * 1000;

    printf("Sorted Elements:\n");

    for (int i = 1; i <= n; i++)
        printf("%d ", H[i]);

    printf("\n");

    printf("Input size: %d\n", n);
    printf("Execution time: %.5f ms\n", cpu_time_used);
}
