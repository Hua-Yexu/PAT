#include <stdio.h>

int is_prime(int i);

int main()
{
    int PM, PN, i, j, count;

    scanf("%d %d", &PM, &PN);
    for(i = 2, count = 0; count < PN; i++)
    {
        if(is_prime(i))
        {
            count++;
            if(count >= PM)
            {
                printf("%d", i);
                if(count < PN)
                    (count-PM+1) % 10 ? putchar(' ') : putchar('\n');
            }
        }
    }

    return 0;
}

int is_prime(int i)
{
    for(int j = 2; j*j <= i; j++)
        if(i % j == 0)
            return 0;

    return 1;
}
