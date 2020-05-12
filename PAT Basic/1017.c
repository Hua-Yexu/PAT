#include <stdio.h>

int main(void)
{
    char A[1001], Q[1001];
    int B, R = 0, i;

    scanf("%s %d", A, &B);

    for(i = 0; A[i] != '\0'; i++)
    {
        R = R * 10 + (A[i]-'0');
        Q[i] = R / B + '0';
        R = R % B;
    }
    Q[i] = '\0';

    if(Q[0] == '0' && Q[1] != '\0')
        printf("%s %d", Q+1, R);
    else
        printf("%s %d", Q, R);

    return 0;
}
