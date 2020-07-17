#include <stdio.h>

int main(void)
{
    char ge[14][5] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly",
                    "aug", "sep", "oct", "nov", "dec"};
    char shi[13][5] = {"tam", "hel", "maa", "huh", "tou", "kes", "hei",
                    "elo", "syy", "lok", "mer", "jou"};

    int N, i, j, figure;
    char in[10];

    scanf("%d", &N);
    getchar();

    for(i = 0; i < N; i++)
    {
        fgets(in, 10, stdin);
        if(in[0] >= '0' && in[0] <= '9')
        {
            figure = 0;
            for(j = 0; in[j] != '\n'; j++)
                figure = figure*10 + (in[j]-'0');
            if(figure/13 && figure%13)
                printf("%s %s\n", shi[figure/13-1], ge[figure%13]);
            else if(figure/13 && figure%13 == 0)
                printf("%s\n", shi[figure/13-1]);
            else
                printf("%s\n", ge[figure]);
        }
        else
        {
            figure = 0;
            for(j = 0; j < 12; j++)
                if(strstr(in, shi[j]))
                    figure = (j+1)*13;
            for(j = 0; j < 13; j++)
                if(strstr(in, ge[j]))
                    figure += j;
            printf("%d\n", figure);
        }
    }


    return 0;
}
