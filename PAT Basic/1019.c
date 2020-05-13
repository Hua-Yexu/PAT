#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comp_down(const void* a, const void* b)
{
    return *(char*)b - *(char*)a;
}

int comp_up(const void* a, const void* b)
{
    return *(char*)a - *(char*)b;
}

int main(void)
{
    int N, sub = 0, x1, x2;
    char str[5] = {0};

    scanf("%d", &N);

    sprintf(str, "%d", N);

    if(str[0] == str[1] && str[1] == str[2] && str[2] == str[3])
    {
        printf("%04d - %04d = 0000", N, N);
        return 0;
    }

    while(sub != 6174)
    {
        qsort(str, strlen(str), sizeof(char), comp_down);
        sscanf(str, "%d", &x1);
        for(int i = 4; i > strlen(str); --i)
            x1 *= 10;

        qsort(str, strlen(str), sizeof(char), comp_up);
        sscanf(str, "%d", &x2);

        sub = x1 - x2;
        printf("%04d - %04d = %04d\n", x1, x2, sub);

        sprintf(str, "%d", sub);
    }

    return 0;
}
