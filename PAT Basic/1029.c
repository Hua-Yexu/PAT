#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char wrong[85];
    char right[85];
    char miss[85];
    char asc[128] = {0};
    int i, j, k;

    scanf("%s", right);
    scanf("%s", wrong);

    for(i = 0, j = 0, k = 0; right[i] != '\0'; i++)
    {
        if(right[i] == wrong[j])
            j++;
        else
        {
            miss[k] = right[i];
            k++;
        }
    }

    for(i = 0; i < k; i++)
    {
        miss[i] = toupper(miss[i]);
        
        if(asc[(int)miss[i]] == 0)
        {
            printf("%c", miss[i]);
            asc[(int)miss[i]] = -1;
        }
    }

    return 0;
}
