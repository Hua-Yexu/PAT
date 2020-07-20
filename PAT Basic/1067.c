//用户输入的密码第一位有可能是空格，不能用scanf

#include <stdio.h>
#include <string.h>

int main(void)
{
    char password[22], input[200], c;
    int N, cnt = 0;

    scanf("%s %d", password, &N);
    getchar();

    while(N--)
    {
        gets(input);

        if(strcmp(input, "#") == 0)
            break;

        if(strcmp(password, input) == 0)
        {
            printf("Welcome in\n");
            break;
        }
        else
            printf("Wrong password: %s\n", input);

        if(N == 0)
        {
            printf("Account locked\n");
            break;
        }
    }

    return 0;
}
