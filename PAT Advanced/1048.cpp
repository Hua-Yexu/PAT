#include <cstdio>

int main(void){
    int N, M;
    int cnt[505] = {0};
    
    scanf("%d %d", &N, &M);
    for(int i = 0, value; i < N; i++){
        scanf("%d", &value);
        cnt[value]++;
    }
    
    for(int i = 1, j; i <= M/2 && i <= 500; i++){
        if((j = M-i) > 500)
            continue;
        if((cnt[i] && i != j && cnt[j]) || (i == j && cnt[i] >= 2)){
            printf("%d %d", i, j);
            return 0;
        }
    }
    
    printf("No Solution");
    
    return 0;
}
