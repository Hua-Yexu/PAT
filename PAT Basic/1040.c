//确定A的的数目、A左边的P的数目x及右面T的数目y，PAT的数目就是x*y；然后根据A的数目累加；

#include <stdio.h>

int main(void)
{
    int P = 0, T = 0, sum;
    char str[100001];
    
    scanf("%s", str);
    
    for(int i = 0; str[i] != '\0'; i++)
        if(str[i] == 'T')
            T++;
    
    for(int i = 0; str[i] != '\0'; i++)
    {
        if(str[i] == 'P')
            P++;
        else if(str[i] == 'A')
            sum += P * T;
        else
            T--;
        
        sum %= 1000000007;
    }
    
    printf("%d", sum);
    
    return 0;
}
