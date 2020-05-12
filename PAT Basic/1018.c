#include <stdio.h>

void prin_max(int A[]);

int main(void)
{
    int N, A_win = 0, A_lost = 0;
    int A[3] = {0};//甲B, C, J赢的次数
    int B[3] = {0};//乙B, C, J赢的次数
    char a, b;

    scanf("%d\n", &N);

    for(int i = 0; i <N; i++)
    {
        scanf("%c %c\n", &a, &b);
        if(a == 'B')
        {
            if(b == 'C')  { A[0]++; A_win++; }
            if(b == 'J')  { B[2]++; A_lost++; }
        }
        if(a == 'C')
        {
            if(b == 'B')  { B[0]++; A_lost++; }
            if(b == 'J')  { A[1]++; A_win++; }
        }
        if(a == 'J')
        {
            if(b == 'B')  { A[2]++; A_win++; }
            if(b == 'C')  { B[1]++; A_lost++; }
        }
    }

    printf("%d %d %d\n", A_win, N-A_win-A_lost, A_lost);
    printf("%d %d %d\n", A_lost, N-A_win-A_lost, A_win);
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
