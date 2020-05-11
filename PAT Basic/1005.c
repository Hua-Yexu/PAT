#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b);

int main(void)
{
    int K, n;
    int test[110] = {0};


    scanf("%d", &K);
    for(int i = 0; i < K; i++)
        scanf("%d", &test[i]);

    for(int i = 0; i < K; i++)
    {
        n = test[i];
        while(n > 1)
        {
            if(n % 2)
                n = (3 * n + 1) / 2;
            else
                n /= 2;

            for(int j = 0; j < K; j++)
                if(n == test[j])
                    test[j] = 0;
        }
    }

  	qsort(test, K, sizeof(int), comp);

    for(int i = 0; test[i]; i++)
    {
        if(i != 0)
            printf(" ");
        printf("%d", test[i]);
    }

    return 0;
}

int comp(const void *a, const void *b) //降序排列
{
    return *(int*)b - *(int*)a;
}
