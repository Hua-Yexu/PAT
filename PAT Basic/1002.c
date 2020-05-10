#include <stdio.h>

int main(void)
{
    char ch;
    int sum = 0;
    char pinyin[10][5] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    char number[1000];

    while((ch = getchar())!= '\n')
        sum += ch - '0';
  
    sprintf(number, "%d", sum);   //将sum的值以字符串的形式写入number
    
    for(int i = 0; number[i] != '\0'; i++)
    {
        if(i)                     //i != 0 时输出空格
        		printf(" ");
        printf("%s", pinyin[number[i]-'0']);
    }

    return 0;
}
