#include <stdio.h>

int main()
{
    int A[5] = {0};
    int N, n, flag_A2 = 1, count_A2 = 0, count_A4 = 0;
    
    scanf("%d", &N);
    
    while(N--)
    {
        scanf("%d", &n);
        switch(n%5)
        {
            case 0: if(n%2 == 0)  A[0] += n;
                    break;
            case 1: A[1] += n*flag_A2;
                    flag_A2 = -flag_A2;
                    count_A2++;
                    break;
            case 2: A[2]++;
                    break;
            case 3: A[3] += n;
                    count_A4++;
                    break;
            case 4: if(A[4] < n)  A[4] = n;
        }
    }
    
    A[0] ? printf("%d", A[0]) : printf("N");
    count_A2 ? printf(" %d", A[1]) : printf(" N");
    A[2] ? printf(" %d", A[2]) : printf(" N");
    A[3] ? printf(" %.1f", (float)A[3] / count_A4) : printf(" N");
    A[4] ? printf(" %d", A[4]) : printf(" N");
    
    return 0;
}
