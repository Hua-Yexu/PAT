#include <stdio.h>

int main(void)
{
    int N, tall;
    char ch;

    scanf("%d %c", &N, &ch);
    if(N % 2)
        tall = N/2 + 1;
    else
        tall = N/2;
    for(int i = 0; i < tall; i++)
    {
        if(i == 0 || i == tall-1)
        {
            for(int j = 0; j < N; j++)
                printf("%c", ch);
            printf("\n");
        }
        else
        {
            for(int j = 0; j < N; j++)
            {
                if(j == 0 || j == N-1)
                    printf("%c", ch);
                else
                    printf(" ");
            }
            printf("\n");
        }
    }

    return 0;
}
