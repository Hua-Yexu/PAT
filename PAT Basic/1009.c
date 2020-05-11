#include <stdio.h>

int main(void)
{
    char store[41][81];
    int i = 0;

    while(scanf("%s", store[i++]) != EOF);
    
    i--;
    while(i--)
    {
        printf("%s", store[i]);
        if(i)
            printf(" ");
    }

    return 0;
}
