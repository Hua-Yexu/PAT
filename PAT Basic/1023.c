#include <stdio.h>

int main(void)
{
    int count[10];
    int d;

    for(int i = 0; i < 10; i++)
        scanf("%d", &count[i]);

    for(int i = 1; ; i++)
        if(count[i])
        {
            printf("%d", i);
            count[i]--;
            break;
        }

    for(int i = 0; i < 10; i++)
        while(count[i]--)
            printf("%d", i);

    return 0;
}
