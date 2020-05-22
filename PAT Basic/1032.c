#include <stdio.h>

int main(void)
{
    int N;
    int sum[100001] = {0};
    int sch_id, sch_max, score, sco_max = 0;
   
    scanf("%d", &N);
    
    for(int i = 0; i < N; i++)
    {
        scanf("%d %d", &sch_id, &score);
        sum[sch_id] += score;
    }

    for(int i = 1; i <= N; i++)
    {
        if(sco_max < sum[i])
        {   
            sco_max = sum[i];
            sch_max = i;
        }
    }

    printf("%d %d", sch_max, sum[sch_max]);

    return 0;
}
