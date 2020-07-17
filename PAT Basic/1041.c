#include <stdio.h>
#include <string.h>

int main(void)
{
    int N, i, comp, M;
    char temp[17];
    char ID[1010][17];
    int test[1010] = {0};

    scanf("%d", &N);

    for(i = 0; i < N; i++)
    {
        scanf("%s", temp);
        scanf("%d", &comp);
        scanf("%d", &test[comp]);
        strcpy(ID[comp], temp);
    }

    scanf("%d", &M);

    for(i = 0; i < M; i++)
    {
        scanf("%d", &comp);
        printf("%s %d\n", ID[comp], test[comp]);
    }

    return 0;
}
