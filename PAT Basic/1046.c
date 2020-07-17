#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(void)
{
    int N, i, drink_a = 0, drink_b = 0;
    int shout_a, hand_a, shout_b, hand_b;

    scanf("%d", &N);
    for(i = 0; i < N; i++)
    {
        scanf("%d %d %d %d", &shout_a, &hand_a, &shout_b, &hand_b);
        if((hand_a == shout_a + shout_b) && (hand_b != shout_a + shout_b))
            drink_b++;
        if((hand_b == shout_a + shout_b) && (hand_a != shout_a + shout_b))
            drink_a++;
    }

    printf("%d %d", drink_a, drink_b);

    return 0;
}
