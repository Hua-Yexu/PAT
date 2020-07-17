#include <stdio.h>

int main(void)
{
    int ascii[128] = {0};
    char c;
    int i, max = 0, alph;

    while( (c = getchar()) != '\n')
    {
        if(isalpha(c))
        {
            c = tolower(c);
            ascii[c]++;
        }
    }

    for(i = (int)('a'); i <= (int)('z'); i++)
    {
        if(ascii[i] > max)
        {
            max = ascii[i];
            alph = i;
        }
    }

    printf("%c %d", (char)alph, max);


    return 0;
}
