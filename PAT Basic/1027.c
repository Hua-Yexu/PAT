#include <stdio.h>

int main(void)
{
    int N, max, i, j, k, rest, sum;
    char mark;

    scanf("%d %c", &N, &mark);

    i = 1;
    max = 1;
    sum = 1;
    while(sum <= N)
    {
        i++;
        max = max + 2;
        sum = (1+max)*i - 1;
    }
    i--;
    max = max - 2;
    sum = (1+max)*i - 1;
    rest = N - sum;

    for(k = i; k > 0; k--, max = max - 2)
    {
        for(j = k; j < i; j++)
            printf(" ");
        for(j = 0; j < max; j++)
            printf("%c", mark);
        printf("\n");
    }
    for(k = 2, max = max + 4; k <= i; k++, max = max + 2)
    {
        for(j = k; j < i; j++)
            printf(" ");
        for(j = 0; j < max; j++)
            printf("%c", mark);
        printf("\n");
    }
    printf("%d", rest);

    return 0;
}
