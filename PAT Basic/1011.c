#include <stdio.h>

int main()
{
    int T;
    long long A, B, C;

    scanf("%d", &T);

    for(int i = 1; i <= T; i++)
    {
        scanf("%lld %lld %lld", &A, &B, &C);
        if(A + B > C)
            printf("Case #%d: true\n", i);
        else
            printf("Case #%d: false\n", i);
    }

    return 0;
}
