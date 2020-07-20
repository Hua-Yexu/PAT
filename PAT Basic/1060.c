#include <stdio.h>

int comp(const void *a, const void *b)
{
    return *(int*)b - *(int*)a;
}

int main(void)
{
    int N, s[100010] = {0}, E;

    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", &s[i]);
    
    qsort(s, N, sizeof(int), comp);

    for(E = 0; E < N && s[E] > E + 1; E++);
    
    printf("%d", E);

    return 0;
}
