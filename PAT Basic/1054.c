#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    int N, flag, dot, K = 0;
    char data[1000];
    double Y, figure, sum = 0.0;

    scanf("%d", &N);

    for(int i = 0; i < N; i++)
    {
        flag = 1;
        dot = 0;
        scanf("%s", data);

        if(data[0] != '-' && isdigit(data[0]) == 0)
            flag = 0;
        for(int j = 1; j < strlen(data); j++)
        {
            if(data[j] == '.')
            {
                dot++;
                if(strlen(data) - j -1 > 2)
                {
                    flag = 0;
                    break;
                }
            }
            else if(isdigit(data[j]) == 0)
            {
                flag = 0;
                break;
            }
        }
        if(dot > 1)
            flag = 0;

        if(flag)
        {
            sscanf(data, "%lf", &figure);
            if(figure > 1000.0 || figure < -1000.0)
                flag = 0;
        }

        if(flag)
        {
            sum += figure;
            K++;
        }
        else
            printf("ERROR: %s is not a legal number\n", data);
    }

    if(K)
    {
        Y = sum / K;
        if(K > 1)
            printf("The average of %d numbers is %.2lf\n", K, Y);
        if(K == 1)
            printf("The average of 1 number is %.2lf\n", Y);
    }
    else
        printf("The average of 0 numbers is Undefined");

    return 0;
}
