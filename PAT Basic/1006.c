#include <stdio.h>

int main(void)
{
    int n;
    int store[3] = {0};
  
    scanf("%d", &n);

    for(int i = 0; n; i++)
    {
        store[i] = n % 10;
        n /= 10;
    }

    while(store[2]--)
        printf("B");
    while(store[1]--)
        printf("S");
    for(int i = 1; i <= store[0]; i++)  
        printf("%d", i);

    return 0;
}
