#include <stdio.h>

int main(void)
{
    int N, i;
    long double data, sum = 0.0;

    scanf("%d", &N);
    for(i = 0; i < N; i++)
    {
        scanf("%llf", &data);
        sum += data * (N-i) * (i+1);
    }

    printf("%.2llf", sum);
  
    return 0;
}
