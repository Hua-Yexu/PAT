#include <stdio.h>

int main(void)
{
    int M, N, A, B, K, a;
    
    scanf("%d %d %d %d %d", &M, &N, &A, &B, &K);
    
    for(int i = 0; i < M; i++)
        for(int j = 0; j < N; j++)
        {
            scanf("%d", &a);
            if(a >= A && a <= B)
                a = K;
            printf("%03d%c", a, j == N-1 ? '\n' : ' ');
        }
    
    return 0;
}
