#include <stdio.h>

int main(void)
{
    char hands[10][5], eyes[10][5], mouths[10][5];
    int cnt_hands = 0, cnt_eyes = 0, cnt_mouths = 0;
    char c;
    int i, request[5], count[5];

    while((c = getchar()) != '\n')
        if(c == '[')
            scanf("%[^]]", hands[cnt_hands++]);
    while((c = getchar()) != '\n')
        if(c == '[')
            scanf("%[^]]", eyes[cnt_eyes++]);
    while((c = getchar()) != '\n')
        if(c == '[')
            scanf("%[^]]", mouths[cnt_mouths++]);

    count[0] = cnt_hands;
    count[1] = cnt_eyes;
    count[2] = cnt_mouths;
    count[3] = cnt_eyes;
    count[4] = cnt_hands;

    for(scanf("%d", &i); i > 0; i--)
    {
        int flag = 1;
        for(int j = 0; j < 5; j++)
        {
            scanf("%d", &request[j]);
            if(request[j] > count[j] || request[j] <= 0)
            {
                flag = 0;
                printf("Are you kidding me? @\\/@\n");
                break;
            }
        }
        
        if(flag)
        {
            int j = 0;
            printf("%s(", hands[request[j++]-1]);
            printf("%s", eyes[request[j++]-1]);
            printf("%s", mouths[request[j++]-1]);
            printf("%s)", eyes[request[j++]-1]);
            printf("%s\n", hands[request[j]-1]);
        }
    }

    return 0;
}
