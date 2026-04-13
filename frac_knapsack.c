#include <stdio.h>

struct object {
    int weight;
    int profit;
    float pwRatio;
};

void sort(struct object o[], int n) {
    struct object temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (o[j].pwRatio < o[j + 1].pwRatio) {
                temp = o[j];
                o[j] = o[j + 1];
                o[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter number of objects: ");
    scanf("%d", &n);

    struct object o[n];

    for (int i = 0; i < n; i++) {
        printf("Object %d (weight profit): ", i + 1);
        scanf("%d %d", &o[i].weight, &o[i].profit);
        o[i].pwRatio = (float)o[i].profit / o[i].weight;
    }

    sort(o, n);

    int size;
    printf("Enter size of knapsack: ");
    scanf("%d", &size);

    float totalProfit = 0.0;
    int rem_wt = size;

    int i = 0;
    while (rem_wt !=0) {
        if (o[i].weight <= rem_wt) {
            totalProfit += o[i].profit;
            rem_wt -= o[i].weight;
        } else {
            totalProfit += (o[i].profit * (float)rem_wt) / o[i].weight;
            rem_wt = 0;
        }
        i++;
    }

    printf("MAXIMUM PROFIT : %.2f\n", totalProfit);

    return 0;
}
