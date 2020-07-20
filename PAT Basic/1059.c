#include <stdio.h>

int is_prime(int a)
{
    for(int i = 2; i*i <= a; i++)
        if(a % i == 0)
            return 0;

    return 1;
}

int main(void)
{
    int N, id, sequ[10000] = {0}, K, seek;

    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &id);
        sequ[id] = i+1;
    }

    scanf("%d", &K);
    for(int i = 0; i < K; i++)
    {
        scanf("%d", &seek);
        printf("%04d: ", seek);

        if(sequ[seek] == 0)
            printf("Are you kidding?\n");
        else if(sequ[seek] == -1)
            printf("Checked\n");
        else
        {
            if(sequ[seek] == 1)
                printf("Mystery Award\n");
            else if(is_prime(sequ[seek]))
                printf("Minion\n");
            else
                printf("Chocolate\n");
            
            sequ[seek] = -1;
        }
    }

    return 0;
}
