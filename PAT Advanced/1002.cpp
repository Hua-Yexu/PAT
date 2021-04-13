#include <cstdio>
using namespace std;

int main(){
    float a[1001] = {0}, A;
    int K, N, cnt = 0;
    
    scanf("%d", &K);
    for(int i = 0; i < K; i++){
        scanf("%d %f", &N, &A);
        a[N] = A;
    }
    
    scanf("%d", &K);
    for(int i = 0; i < K; i++){
        scanf("%d %f", &N, &A);
        a[N] += A;
    }
    
    for(int i = 0; i < 1001; i++)
        if(a[i] != 0)
            cnt++;
    
    printf("%d", cnt);
    for(int i = 1000; i >= 0; i--)
        if(a[i] != 0)
            printf(" %d %.1f", i, a[i]);
    
    return 0;
}
