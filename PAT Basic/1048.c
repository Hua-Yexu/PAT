#include <stdio.h>
#include <string.h>

int main(void)
{
    char A[110], B[110];
    int cnt_a, cnt_b;

    scanf("%s %s", A, B);
    cnt_a = strlen(A);
    cnt_b = strlen(B);
    
    if(cnt_b < cnt_a)//若A比B长需添0
    {
        int i = cnt_a - cnt_b;
        for(int j = cnt_b+i; j >= i; j--)
                B[j] = B[j-i];
        for(i--; i >= 0; i--)
            B[i] = '0';
        cnt_b = cnt_a;
    }
            

    for(int a = --cnt_a, b = --cnt_b, i = 1; a >= 0 && b >= 0; a--, b--, i++)
    {
        if(i % 2)
        {
            B[b] += A[a] - '0';
            B[b] = (B[b] - '0') % 13 + '0';
            if(B[b] == '9' + 1)
                B[b] = 'J';
            else if(B[b] == '9' + 2)
                B[b] = 'Q';
            else if(B[b] == '9' + 3)
                B[b] = 'K';
        }
        else
        {
            B[b] = B[b] - A[a] + '0';
            if(B[b] < '0')
                B[b] += 10;
        }
    }
            
    printf("%s", B);

    return 0;
}
