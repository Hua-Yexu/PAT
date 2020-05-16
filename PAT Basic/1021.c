#include <stdio.h>

int main(void)
{
    int N, count[10] = {0};
    char c;

    while((c = getchar()) && c != '\n')
        count[(int)c-'0']++;

    for(int i = 0; i < 10; i++)
        if(count[i])
            printf("%d:%d\n", i, count[i]);

    return 0;
}
