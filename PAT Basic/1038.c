#include <stdio.h>

int main(void)
{
    int N, K, point;
    int count[110] = {0};

    scanf("%d", &N);

    for(int i = 0; i < N; i++)
    {
        scanf("%d", &point);
        count[point]++;
    }

    scanf("%d", &K);

    for(int i = 0; i < K; i++)
    {
        scanf("%d", &point);
        if(i)
            printf(" %d", count[point]);
        else
            printf("%d", count[point]);
    }

    return 0;
}
