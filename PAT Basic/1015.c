#include <stdio.h>
#include <stdlib.h>

typedef struct form
{
    int id;
    int vir;
    int tal;
}*p;

int comp(const void *a, const void *b);

int main()
{
    int N, L, H, M = 0;
    int count[4] = {0};
    struct form data[4][100010], store;

    scanf("%d %d %d", &N, &L, &H);
    for(int i = 0; i < N; i++)
    {
        scanf("%d %d %d", &store.id, &store.vir, &store.tal);
        if(store.tal >= L && store.vir >= L)
        {
            M++;
            if(store.tal >= H && store.vir >= H)
                data[0][count[0]++] = store;
            else if(store.vir >= H)
                data[1][count[1]++] = store;
            else if(store.vir >= store.tal)
                data[2][count[2]++] = store;
            else
                data[3][count[3]++] = store;
        }
    }

    for(int i = 0; i < 4; i++)
        qsort(data[i], count[i], sizeof(data[0][0]), comp);

    printf("%d\n", M);
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < count[i]; j++)
            printf("%d %d %d\n", data[i][j].id, data[i][j].vir, data[i][j].tal);

    return 0;
}

int comp(const void *a, const void *b)
{
    p p1 = (p*) a;
    p p2 = (p*) b;
    int sum1 = p1->tal + p1->vir;
    int sum2 = p2->tal + p2->vir;

    if(sum1 != sum2)
        return sum2 - sum1;
    else if(p1->vir != p2->vir)
        return p2->vir - p1->vir;
    else
        return p1->id - p2->id;
}
