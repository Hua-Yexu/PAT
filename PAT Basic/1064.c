#include <stdio.h>

int main(void)
{
    int N, sum, cnt = 0, flag = 0;
    char nums[5];
    int counts[37] = {0};

    scanf("%d", &N);

    while(N--)
    {
        scanf("%s", nums);
        sum = 0;
        for(int i = 0; nums[i] != '\0'; i++)
            sum += nums[i] - '0';
        counts[sum]++;
        if(counts[sum] == 1)
            cnt++;
    }

    printf("%d\n", cnt);
    for(int i = 0; i < 37; i++)
        if(counts[i])
        {
            if(flag)
                putchar(' ');
            printf("%d", i);
            flag = 1;
        }

    return 0;
}
