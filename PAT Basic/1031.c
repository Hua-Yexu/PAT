#include <stdio.h>

int main(void)
{
    char data[19];
    int N, i, j, sum, flag, count;
    char M[12] = {"10X98765432"};
    int quan[17] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
    
    scanf("%d", &N);

    for(i = 0, count = 0; i < N; i++)
    {
        scanf("%s", data);
        
        for(j = 0, sum = 0, flag = 1; j < 17; j++)
        {
            if(isdigit(data[j]))
                sum += ((int)data[j]-'0')*quan[j];
            else
            { 
                flag = 0;
                break; 
            }
        }
        
        if(flag && M[sum%11] == data[17])
            count++;
        else
            printf("%s\n",data);
    }
    
    if(count == N)
        printf("All passed");
    
    return 0;
}
