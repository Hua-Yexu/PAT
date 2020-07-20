#include <stdio.h>
#include <math.h>

int main(void)
{
    int N, real, ima;
    double result, max = 0;

    scanf("%d", &N);

    for(int i = 0; i < N; i++)
    {
        scanf("%d %d", &real, &ima);
        result = sqrt(real*real+ima*ima);
        if(result > max)
            max = result;
    }

    printf("%.2lf", max);

    return 0;
}
