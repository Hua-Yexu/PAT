#include <stdio.h>
#include <math.h>

int comp(const void *a, const void *b)
{
    return *(int*)b - *(int*)a;
}

int main(void)
{
    int N, data[100001], m, n;

    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", &data[i]);

    qsort(data, N, sizeof(int), comp);

    n = (int)sqrt(N);
    while(N % n)
        n--;
    m = N / n;

    int matrix[m][n];
    int up = 0, right = n-1, down = m-1, left = -1, x = 0, k;
    while(x < N)
    {
        for(k = ++left; k <= right; k++)//向右
            matrix[up][k] = data[x++];
        if(x == N) break;
        
        for(k = ++up; k <= down; k++)//向下
            matrix[k][right] = data[x++];
        if(x == N) break;
        
        for(k = --right; k >= left; k--)//向左
            matrix[down][k] = data[x++];
        if(x == N) break;
        
        for(k = --down; k >= up; k--)//向上
            matrix[k][left] = data[x++];
        if(x == n) break;
    }

    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            printf("%d%c", matrix[i][j], j == n-1 ? '\n' : ' ');

    return 0;
}
