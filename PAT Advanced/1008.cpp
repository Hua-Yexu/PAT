#include <cstdio>

int main(void){
    int N, floor = 0, next, sub, sum = 0;
    
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &next);
        sub = next - floor;
        if(sub > 0)
            sum += 6 * sub;
        else
            sum += 4 * (-sub);
        sum += 5;
        floor = next;
    }
    
    printf("%d", sum);
    
    return 0;
}
