#include <stdio.h>
#include <string.h>

typedef struct
{
    int point;
    int all;
    int right;
    char options[6];
}form;

int main(void)
{
    int N, M, cnt_wrong[100] = {0}, stu_point[1000] = {0};
    form info[100];

    scanf("%d %d", &N, &M);

    for(int i = 0, j; i < M; i++)
    {
        scanf("%d %d %d", &info[i].point, &info[i].all, &info[i].right);
        for(j = 0; j < info[i].right; j++)
            scanf(" %c", &info[i].options[j]);
        info[i].options[j] = '\0';
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            int num;
            char ans[6] = {0}, c;
            while((c = getchar()) != '(');
            scanf("%d", &num);
            for(int k = 0; k < num; k++)
                scanf(" %c", &ans[k]);
            if(strcmp(ans, info[j].options) == 0)
                stu_point[i] += info[j].point;
            else
                cnt_wrong[j]++;
        }
    }

    for(int i = 0; i < N; i++)
        printf("%d\n", stu_point[i]);

    int max = 0, flag = 1;
    for(int i = 0; i < M; i++)
        if(max < cnt_wrong[i])
            max = cnt_wrong[i];
    if(max == 0)
        printf("Too simple");
    else
    {
        printf("%d", max);
        for(int i = 0; i < M; i++)
            if(max == cnt_wrong[i])
                printf(" %d", i+1);
    }

    return 0;
}
