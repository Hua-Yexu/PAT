#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int comp(const void * a, const void * b);

int main(void)
{
    int N, i, j, count = 0, flag, max;
    int data[100010];
    int copy_sort[100010];
    int mainelem[100010];

    scanf("%d", &N);
    for(i = 0; i < N; i++)
    {
        scanf("%d", &data[i]);
        copy_sort[i] = data[i];
    }

    qsort(copy_sort, N, sizeof(int), comp);

    for(i = 0, max = 0; i < N; i++)
    {
        if(copy_sort[i] == data[i] && copy_sort[i] > max)
        {
            mainelem[count] = copy_sort[i];
            count++;
        }
        if(data[i] > max)
            max = data[i];
    }

    printf("%d\n", count);
    if(count)
    {
        printf("%d", mainelem[0]);
        for(i = 1; i < count; i++)
            printf(" %d", mainelem[i]);
    }
    printf("\n");//必须要\n，否则会有presentation error

    return 0;
}

int comp(const void * a, const void * b)
{
    return *(int*)a - *(int*)b;
}
