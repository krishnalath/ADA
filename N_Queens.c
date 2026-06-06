#include <stdio.h>
#include <stdlib.h>

int pos[20];

int safe(int row, int col)
{
    for(int i = 0; i < row; i++)
    {
        if(pos[i] == col ||
           abs(pos[i] - col) == abs(i - row))
            return 0;
    }
    return 1;
}

void solve(int row, int n)
{
    if(row == n)
    {
        printf("\nSolution:\n");

        for(int i = 0; i < n; i++)
            printf("Row %d -> Column %d\n",
                    i+1, pos[i]+1);

        return;
    }

    for(int col = 0; col < n; col++)
    {
        if(safe(row,col))
        {
            pos[row] = col;
            solve(row+1,n);
        }
    }
}

int main()
{
    int n;

    printf("Enter N: ");
    scanf("%d",&n);

    solve(0,n);

    return 0;
}
