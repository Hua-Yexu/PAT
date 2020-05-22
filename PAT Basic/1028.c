//这个方法做烦琐了，直接按字符串输入
#include <stdio.h>

struct info
{
    char name[10];
    int year;
    int month;
    int day;
}a, max, min;

int is_avai(struct info a)
{
    if(a.year < 1814 || (a.year == 1814 && a.month < 9) ||
        (a.year == 1814 && a.month == 9 && a.day < 6))
        return 0;
    if(a.year > 2014 || (a.year == 2014 && a.month > 9) ||
        (a.year == 2014 && a.month == 9 && a.day > 6))
        return 0;
    return 1;
}

int is_older(struct info a, struct info max)
{
    if(a.year > max.year || (a.year == max.year && a.month > max.month) ||
        (a.year == max.year && a.month == max.month && a.day > max.day))
        return 0;
    return 1;
}

int is_younger(struct info a, struct info min)
{
    if(a.year < min.year || (a.year == min.year && a.month < min.month) ||
        (a.year == min.year && a.month == min.year && a.day < min.day))
        return 0;
    return 1;
}

int main(void)
{
    int N, i, count = 0;

    scanf("%d", &N);
    max.year = 2015;
    min.year = 1813;

    for(i = 0; i < N; i++)
    {
        scanf("%s %d/%d/%d", a.name, &a.year, &a.month, &a.day);
        if(is_avai(a))
        {
            count++;
            if(is_older(a, max))
                max = a;
            if(is_younger(a, min))
                min = a;
        }
    }
	if(count)
   	printf("%d %s %s", count, max.name, min.name);
  else
    printf("0");

    return 0;
}

