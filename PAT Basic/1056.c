#include <stdio.h>

int main(void)
{
    int N, a, sum = 0;
    
    scanf("%d", &N);
        
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &a);
        sum += (a*10 + a) * (N-1);
    }
    
    printf("%d", sum);
    
    return 0;
}
