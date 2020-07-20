#include <stdio.h>

typedef struct
{
    char name[10];
    int tall;
}node;

int comp(const void *a, const void *b)
{
    node * c = (node*)a;
    node * d = (node*)b;

    if(d->tall == c->tall)
        return strcmp(c->name, d->name);
    else
        return d->tall - c->tall;
}

void print(node data[], int start, int length)
{
    int i = start + length - 1;
    if(length % 2)
        i -= 1;
    for(; i > start; i -= 2)
        printf("%s ", data[i].name);
    for(i = 0; i < length; i += 2 )
        printf("%s%c", data[i+start].name, (i+2) < length ? ' ' : '\n');
}

int main(void)
{
    int N, K;
    node data[10001];

    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; i++)
        scanf("%s %d", data[i].name, &data[i].tall);

    qsort(data, N, sizeof(data[0]), comp);

    int L = N / K;
    print(data, 0, L + N % K);
    for(int i = L + N % K; i < N; i += L)
        print(data, i, L);

    return 0;
}
