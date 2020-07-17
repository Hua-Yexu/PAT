#include <stdio.h>

int main(void)
{
    int N, i, team_num, per_num, point, max_num, max_point;
    int team[1010] = {0};


    scanf("%d", &N);
    for(i = 0; i < N; i++)
    {
        scanf("%d-%d %d", &team_num, &per_num, &point);
        team[team_num] += point;
    }

    for(i = 0, max_point = 0; i < 1000; i++)
    {
        if(team[i] > max_point)
        {
            max_point = team[i];
            max_num = i;
        }
    }

    printf("%d %d", max_num, max_point);

    return 0;
}
