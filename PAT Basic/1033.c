#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int asc[128] = {0};
    char c;
    
    while((c = getchar()) != '\n')
    {
        asc[c] = -1;
        if(isupper(c))
            asc[tolower(c)] = -1;
    }
    
    if(asc['+'] == -1)
        for(c = 'A'; c <= 'Z'; c++)
            asc[c] = -1;
    
    while((c = getchar()) != '\n')
        if(asc[c] != -1)
            putchar(c);

    return 0;
}
