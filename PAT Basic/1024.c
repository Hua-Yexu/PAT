#include <stdio.h>
#include <string.h>

int main(void)
{
    char A[10000];
    char *exp, *dot, *p;
    int e_value;

    scanf("%s", A);

    exp = strchr(A, 'E');
    dot = strchr(A, '.');
    sscanf(exp+2, "%d", &e_value);

    if(A[0] == '-')
        putchar('-');

    if(*(exp+1) == '+')
    {
        printf("%c", A[1]);
        for(p = dot+1; p-dot <= e_value || p < exp; p++)
        {
            if(p < exp)
            {
                if(p-dot == e_value+1)
                    putchar('.');
                printf("%c", *p);
            }
            else
                putchar('0');
        }
    }
    else
    {
        printf("0.");
        for(int i = 0; i < e_value-1; i++)
            putchar('0');
        printf("%c", A[1]);
        for(p = dot+1; p < exp; p++)
            printf("%c", *p);
    }

    return 0;
}
