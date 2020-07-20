#include <stdio.h>
#include <stdlib.h>

int cmp(const void * a, const void * b)
{
    return *(int*)a - *(int*)b;
}

int main(void)
{
    int N, M, a, b, cnt = 0;
    int couple[100000];
    int party[100000] = {0};
    int single[10000];

    for(int i = 0; i < 100000; i++)
        couple[i] = -1;

    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%d %d", &a, &b);
        couple[a] = b;
        couple[b] = a;
    }

    scanf("%d", &M);
    for(int i = 0; i < M; i++)
    {
        scanf("%d", &a);
        party[a] = 1;
    }

    for(int i = 0; i < 100000; i++)
    {
        if(party[i] == 1)
            if(couple[i] == -1 || party[couple[i]] == 0) 
                single[cnt++] = i;
    }

    qsort(single, cnt, sizeof(int), cmp);

    printf("%d\n", cnt);
    for(int i = 0; i < cnt; i++)
        printf("%05d%c", single[i], i == cnt-1 ? '\n' : ' ');

    return 0;
}
