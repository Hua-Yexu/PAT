#include <stdio.h>

int main(void)
{
    int N, M, st_ans, sum;
    int scores[100], anss[100];
    
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; i++)
        scanf("%d", &scores[i]);
    for(int i = 0; i < M; i++)
        scanf("%d", &anss[i]);
    
    for(int i = 0; i < N; i++)
    {
        sum = 0;
        for(int j = 0; j < M; j++)
        {
            scanf("%d", &st_ans);
            if(st_ans == anss[j])
                sum += scores[j];
        }
        printf("%d\n", sum);
    }
    
    return 0;
}
