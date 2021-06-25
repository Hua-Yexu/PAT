#include <cstdio>

int main(void){
    int N;
    long long a, b, c;
    
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%lld %lld %lld", &a, &b, &c);
        printf("Case #%d: %s\n", i+1, b > c-a ? "true" : "false");//避免溢出，使用减法
    }
    
    return 0;
}
