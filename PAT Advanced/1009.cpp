#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct{
    int exp;
    float coe;
}form;

int main(void){
    int K1, K2;
    form pol1[12], pol2[12];
    float result[2002];
    
    fill(result, result+2001, 0);
    
    scanf("%d", &K1);
    for(int i = 0; i < K1; i++)
        scanf("%d %f", &pol1[i].exp, &pol1[i].coe);
    scanf("%d", &K2);
    for(int i = 0; i < K2; i++)
        scanf("%d %f", &pol2[i].exp, &pol2[i].coe);
    
    for(int i = 0; i < K1; i++)
        for(int j = 0; j < K2; j++)
            result[pol1[i].exp + pol2[j].exp] += pol1[i].coe * pol2[j].coe;
    
    int cnt = 0;
    for(int i = 0; i < 2001; i++)
        if(result[i])
            cnt++;
    
    printf("%d", cnt);
    for(int i = 2000; i >= 0; i--)
        if(result[i])
            printf(" %d %.1f", i, result[i]);
    
    return 0;
}
