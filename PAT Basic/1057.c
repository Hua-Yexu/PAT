#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char c;
    int sum = 0, cnt1 = 0, cnt0 = 0;

    while((c = getchar()) != EOF)
        if(isalpha(c))
            sum += tolower(c) - 'a' + 1;

    while(sum)
    {
        if(sum % 2)
            cnt1++;
        else
            cnt0++;
        sum /= 2;
    }

    printf("%d %d", cnt0, cnt1);

    return 0;
}
