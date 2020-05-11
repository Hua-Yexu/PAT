#include <stdio.h>

int judge(char []);

int main(void)
{
    char string[110];
    int N;
    scanf("%d", &N);
    while(N--)
    {
        scanf("%s", string);
        if(judge(string))//是否符合要求
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}

int judge(char string[])
{
    int cnt_p = 0, cnt_t = 0;              //P、T的个数
    int p, t, i;                           //p、t分别为P、T在数组中的下标
    for(i = 0; string[i] != '\0'; ++i)
    {
        if(string[i] == 'A')
            continue;
        else if(string[i] == 'P')
        {
            ++cnt_p;
            p = i;
        }
        else if(string[i] == 'T')
        {
            ++cnt_t;
            t = i;
        }
        else                               //P、A、T之外的字符
            return 0;
    }
    if(cnt_p != 1 || cnt_t != 1)           //P或者T的个数不为1
        return 0;
    if((t-p-1 == 0) || (p * (t-p-1)) != (i-t-1))          //PT之间A的个数为0，或者P前A的个数乘以PT之间A的个数不等于T后A的个数
        return 0;

    return 1;
}
