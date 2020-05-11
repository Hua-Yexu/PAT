#include <stdio.h>

int is_prime(int i);

int main(void)
{
    int count = 0;
    int N;

    scanf("%d", &N);

    for(int i = 3; i+2 <= N; i = i+2)
        if(is_prime(i) && is_prime(i+2))
            count++;

    printf("%d", count);

    return 0;
}

int is_prime(int i)
{  
    for(int a = 2; a*a <=i; a++)
        if(i % a == 0)
            return 0;

    return 1;
}
