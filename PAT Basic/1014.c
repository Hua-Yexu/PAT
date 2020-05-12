#include <stdio.h>

int main(void)
{
    char codes[4][62];
    int i;
    char week_abbr[7][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

    for(i = 0; i < 4; i++)
        scanf("%s", codes[i]);

    for(i = 0; ; i++)
    {
        if(codes[0][i] >= 'A' && codes[0][i] <= 'G' && codes[0][i] == codes[1][i])
        {
            printf("%s ", week_abbr[codes[0][i]-'A']);
            break;
        }
    }

    for(i = i+1; ; i++)
    {
        if(codes[0][i] >= '0' && codes[0][i] <= '9' && codes[0][i] == codes[1][i])
        {
            printf("%02d:", codes[0][i]-'0');
            break;
        }
        if(codes[0][i] >= 'A' && codes[0][i] <= 'N' && codes[0][i] == codes[1][i])
        {
            printf("%02d:", codes[0][i]-'A'+10);
            break;
        }
    }

    for(i = 0; ; i++)
    {
        if(((codes[2][i] >= 'A' && codes[2][i] <= 'Z') || (codes[2][i] >= 'a' && codes[2][i] <= 'z'))
           && codes[2][i] == codes[3][i])
        {
            printf("%02d", i);
            break;
        }
    }

    return 0;
}
