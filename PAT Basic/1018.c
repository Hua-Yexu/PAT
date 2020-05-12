#include <stdio.h>

void prin_max(int A[]);

int main(void)
{
    int N, A_win = 0, same = 0;
    int A[3] = {0};//甲B, C, J赢的次数
    int B[3] = {0};//乙B, C, J赢的次数
    char a, b;

    scanf("%d\n", &N);

    for(int i = 0; i <N; i++)
    {
        scanf("%c %c\n", &a, &b);
        if(a == 'B')
        {
            if(b == 'B')  same++;
            if(b == 'C')  { A[0]++; A_win++; }
            if(b == 'J')  B[2]++;
        }
        if(a == 'C')
        {
            if(b == 'B')  B[0]++;
            if(b == 'C')  same++;
            if(b == 'J')  { A[1]++; A_win++; }
        }
        if(a == 'J')
        {
            if(b == 'B')  { A[2]++; A_win++; }
            if(b == 'C')  B[1]++;
            if(b == 'J')  same++;
        }
    }

    printf("%d %d %d\n", A_win, same, N-A_win-same);
    printf("%d %d %d\n", N-A_win-same, same, A_win);
    prin_max(A);
    putchar(' ');
    prin_max(B);

    return 0;
}

void prin_max(int A[])
{
    if(A[0] >= A[1] && A[0] >= A[2])
        printf("B");
    else if(A[1] >= A[2])
        printf("C");
    else
        printf("J");
}
