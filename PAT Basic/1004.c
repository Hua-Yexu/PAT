#include <stdio.h>

int main(void)
{
    int N;
    struct info
    {
        char name[11];
        char id[11];
        int grade;
    }max, min, input;
  
    scanf("%d", &N);
    max.grade = 0;
    min.grade = 100;
    
    while(N--)
    {
        scanf("%s %s %d", &input.name, &input.id, &input.grade);
        
        if(max.grade < input.grade)
            max = input;
        if(min.grade > input.grade)
            min = input;
    }
  
    printf("%s %s\n", max.name, max.id);
    printf("%s %s", min.name, min.id);
  
    return 0;
}
