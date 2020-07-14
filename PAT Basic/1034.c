#include <stdio.h>

void get_sim(long num[], long a, long b)
{
    num[0] = a / b;
    a = a % b;

    long x = abs(a), y = abs(b), r;
    while(x != 0)
    {
        r = y % x;
        y = x;
        x = r;
    }

    num[1] = a / y;
    num[2] = b / y;

    if(num[2] < 0)
    {
        num[1] = -num[1];
        num[2] = -num[2];
    }
    if(num[0] < 0 && num[1] < 0)
        num[1] = -num[1];
}

void put_result(long num1[], char c, long num2[], long num3[])
{
    print(num1);
    printf(" %c ", c);
    print(num2);
    printf(" = ");
    print(num3);
    printf("\n");
}

void print(long num[])
{
    if(num[0] < 0 || num[1] < 0)
        printf("(");
    
    if(num[0])
    {
        printf("%d", num[0]);
        if(num[1])
            printf(" %d/%d", num[1], num[2]);
    }
    else
        if(num[1])
            printf("%d/%d", num[1], num[2]);
        else
            printf("0");

    if(num[0] < 0 || num[1] < 0)
        printf(")");
}

int main(void)
{
    long a1, b1, a2, b2, a3, b3;
    long num1[3], num2[3], num3[3];
    
    scanf("%ld/%ld", &a1, &b1);
    scanf("%ld/%ld", &a2, &b2);
    
    num1[1] = a1; num1[2] = b1;
    num2[1] = a2; num2[2] = b2;
    get_sim(num1, a1, b1);
    get_sim(num2, a2, b2);
    
    //add
    a3 = a1 * b2 + a2 * b1;
    b3 = b1 * b2;
    get_sim(num3, a3, b3);
    put_result(num1, '+', num2, num3);

    //substract
    a3 = a1 * b2 - a2 * b1;
    b3 = b1 * b2;
    get_sim(num3, a3, b3);
    put_result(num1, '-', num2, num3);

    //multiple
    a3 = a1 * a2;
    b3 = b1 * b2;
    get_sim(num3, a3, b3);
    put_result(num1, '*', num2, num3);

    //divide
    a3 = a1 * b2;
    b3 = a2 * b1;
    if(b3 == 0)
    {
        print(num1);
        printf(" / 0 = Inf\n");
    }
    else
    {
        get_sim(num3, a3, b3);
        put_result(num1, '/', num2, num3);
    }

    return 0;
}
