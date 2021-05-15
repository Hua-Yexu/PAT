#include <cstdio>

int N, M, K;
int road[1005][1005] = {0};
    
void dfs(int list[], int i){
    list[i] = 1;
    int j;
    for(j = 1; j <= N; j++)
        if(road[i][j] == 1 && list[j] == 0)
            dfs(list, j);
}

int main(void){
    scanf("%d %d %d", &N, &M, &K);
    for(int i = 0, c1, c2; i < M; i++){
        scanf("%d %d", &c1, &c2);
        road[c1][c2] = road[c2][c1] = 1;
    }
    
    for(int i = 0, k; i < K; i++){
        scanf("%d", &k);
        int list[1005] = {0};
        list[k] = 1;
        int cnt = -1;
        
        for(int j = 1; j <= N; j++){
            if(list[j] == 0){
                dfs(list, j);
                cnt++;
            }
        }
        
        printf("%d\n", cnt);
    }
    
    return 0;
}
