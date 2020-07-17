#include <stdio.h>

int main(void)
{
    int sell[128] = {0};
    int rest = 0, need = 0;
    char c;

    while((c = getchar()) && c != '\n')
        sell[c]++;

    while((c = getchar()) && c != '\n')
        sell[c]--;

    for(int i = 0; i < 128; i++)
    {
        if(sell[i] > 0)
            rest += sell[i];
        if(sell[i] < 0)
            need -= sell[i];
    }

    if(need)
        printf("No %d", need);
    else
        printf("Yes %d", rest);

    return 0;
}
