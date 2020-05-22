#include <stdio.h>
#include <stdlib.h>

int comp(const void * a, const void * b)
{
    return *(int*)a - *(int*)b;
}

int main(void)
{
    int N, p, i, j, max, count;
    int data[100010];

    scanf("%d %d", &N, &p);
    for(i = 0; i < N; i++)
        scanf("%d", &data[i]);

    qsort(data, N, sizeof(int), comp);

    for(i = 0, max = 0; i+max < N; i++)
    {
        for(j = i+max; j < N && data[j] <= 1L * data[i] * p; j++);
        count = j - i;
        if(count > max)
            max = count;
    }

    printf("%d", max);

    return 0;
}
