/*使用qsort第一个测试点无法通过，为什么啊？？？*/

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    double storage;
    double price;
    double unit;
}cake;

/*int comp(const void *a, const void *b)
{
    return d->unit - c->unit;
}*/

void down_sort(cake data[], int N)
{
    int i;
    cake store;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N-i-1; j++)
            if(data[j].unit < data[j+1].unit)
            {
                store = data[j];
                data[j] = data[j+1];
                data[j+1] = store;
            }
}

int main(void)
{
    int N;
    double D, max = 0.0;
    cake data[1001];

    scanf("%d %lf", &N, &D);
    for(int i = 0; i < N; i++)
        scanf("%lf", &data[i].storage);
    for(int i = 0; i < N; i++)
    {
        scanf("%lf", &data[i].price);
        data[i].unit = data[i].price / data[i].storage;
    }

    //qsort(data, N, sizeof(data[0]), comp);
    down_sort(data, N);

    for(int i = 0; D != 0 && i < N; i++)
    {
        if(D >= data[i].storage)
        {
            max += data[i].price;
            D -= data[i].storage;
        }
        else
        {
            max += D * data[i].price / data[i].storage;
            D = 0;
        }
    }
    
    printf("%.2lf", max);

    return 0;
}
