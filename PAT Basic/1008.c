#include <stdio.h>

void reverse(int *, int, int);

int main(void)
{
    int M, N;
    int A[100];

    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++)
        scanf("%d", &A[i]);
  
    M = M % N;

    reverse(A, 0, N-M-1);
    reverse(A, N-M, N-1);
    reverse(A, 0, N-1);

    printf("%d", A[0]);
    for(int i = 1; i < N; i++)
        printf(" %d", A[i]);

    return 0;
}

void reverse(int n[], int a, int b)
{
    int store;

    while(a < b)
    {
        store = n[a];
        n[a] = n[b];
        n[b] = store;
        a++;
        b--;
    }
}
