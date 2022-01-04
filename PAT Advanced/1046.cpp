#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    int N;
    scanf("%d", &N);
    
    vector<int> D(N+1, 0);
    for(int i = 1; i <= N; i++){
        scanf("%d", &D[i]);
        D[i] += D[i-1];
    }
    
    int M;
    scanf("%d", &M);
    for(int i = 0; i < M; i++){
        int c1, c2, d1, d2;
        scanf("%d %d", &c1, &c2);
        if(c1 > c2)
            swap(c1, c2);
        d1 = D[c2-1] - D[c1-1];
        d2 = D[N] - D[c2-1] + D[c1-1];
        printf("%d\n", min(d1, d2));
    }
    
    return 0;
}
