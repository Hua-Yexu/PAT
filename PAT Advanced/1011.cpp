#include <cstdio>

int main(void){
    float W, T, L, profit[3], sum;
    char choose[3];
    
    for(int i = 0; i < 3; i++){
        scanf("%f %f %f", &W, &T, &L);
        
        if(W > T && W > L)
            profit[i] = W, choose[i] = 'W';
        if(T > W && T > L)
            profit[i] = T, choose[i] = 'T';
        if(L > T && L > W)
            profit[i] = L, choose[i] = 'L';
    }
    
    sum = (profit[0] * profit[1] * profit[2] * 0.65 - 1) * 2;
    
    printf("%c %c %c ", choose[0], choose[1], choose[2]);
    printf("%.2f", sum);
    
    return 0;
}
