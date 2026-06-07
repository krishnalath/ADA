#include <stdio.h>

int max(int a,int b)
{
    return (a>b)?a:b;
}

int main()
{
    int n,m;

    printf("Enter number of rows and columns: ");
    scanf("%d%d",&n,&m);

    int coin[n][m];
    int dp[n+1][m+1];

    printf("Enter coin matrix:\n");

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            scanf("%d",&coin[i][j]);
    }

    for(int j=0;j<=m;j++)
        dp[0][j]=0;

    for(int i=0;i<=n;i++)
        dp[i][0]=0;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            dp[i][j] =
                max(dp[i-1][j], dp[i][j-1])
                + coin[i-1][j-1];
        }
    }

    printf("Maximum coins collected = %d\n",
           dp[n][m]);

    return 0;
}
