#include<cstdio>
#include<vector>
#include<climits>
using namespace std;

#define OPEN 8*60
#define CLOSE 17*60

int main(void){
    int N, M, K, Q;
    scanf("%d %d %d %d", &N, &M, &K, &Q);
    
    vector<int> pro(K+1);
    for(int i = 1; i <= K; i++)
        scanf("%d", &pro[i]);
    
    vector<int> cus(K+1);
    vector<vector<int>> line(N+1);
    int i;
    for(i = 1; i <= N && i <= K; i++){
        cus[i] = OPEN;
        line[i].push_back(cus[i] + pro[i]);
    }
    for(int j = 0; j < M-1 && i <= K; j++){
        for(int k = 1; k <= N && i <= K; k++){
            cus[i] =line[k][j];
            line[k].push_back(cus[i] + pro[i]);
            i++;
        }
    }
    for(i; i <= K; i++){
        int u, minn = INT_MAX;
        for(int j = 1; j <= N; j++){
            if(line[j][0] < minn){
                u = j;
                minn = line[j][0];
            }
        }
        cus[i] = line[u][M-1];
        line[u].erase(line[u].begin());
        line[u].push_back(cus[i] + pro[i]);
    }
    
    for(int j = 0; j < Q; j++){
        int q;
        scanf("%d", &q);
        if(cus[q] < CLOSE) printf("%02d:%02d\n", (cus[q]+pro[q])/60, (cus[q]+pro[q])%60);
        else printf("Sorry\n");
    }
    
    return 0;
}
