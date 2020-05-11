#include <stdio.h>

int main(void)
{
    int cof[1010], exp[1010];
    int i = 0, j = 0;

    while(scanf("%d", &cof[i++]) != EOF)
        scanf("%d", &exp[j++]);

    for(i = 0; i < j; i++)
    {
        cof[i] = cof[i] * exp[i];
        --exp[i];
    }
  
		if(cof[i] == 0 && j == 1)
    		printf("0 0");
    else
        for(i = 0; i < j; i++)
        {
            if(cof[i])
            {
                if(i)
                    printf(" ");
                printf("%d %d", cof[i], exp[i]);
            } 
        }

    return 0;
}
