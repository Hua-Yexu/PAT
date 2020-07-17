#include <stdio.h>

int main()
{
    int N, D, K, i, j;
    double e, elec;
    int count_less, count_possible_nobody = 0, count_nobody = 0;

    scanf("%d", &N);
    scanf("%lf", &e);
    scanf("%d", &D);

    for(i = 0; i < N; i++)
    {
        scanf("%d", &K);
        count_less = 0;
        for(j = 0; j < K; j++)
        {
            scanf("%lf", &elec);
            if(elec < e)
                count_less++;
        }
        if(count_less * 2 > K)
            if(K > D)
                count_nobody++;
            else
                count_possible_nobody++;
    }

    printf("%.1lf%% %.1lf%%", (double)count_possible_nobody / (double)N * 100,
           (double)count_nobody / (double)N * 100);

    return 0;
}
