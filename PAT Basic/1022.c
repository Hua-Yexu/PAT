#include <stdio.h>

int main(void)
{
    int A, B, sum, D, i;
    int result[32];

    scanf("%d %d %d", &A, &B, &D);

    sum = A + B;
    for(i = 0; sum; i++)
    {
        result[i] = sum % D;
        sum /= D;
    }
    
    if(A == 0 && B == 0)
        printf("0");
    else
        for(i--; i >= 0; i--)
            printf("%d", result[i]);

    return 0;
}
