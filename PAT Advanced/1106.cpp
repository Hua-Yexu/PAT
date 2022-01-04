#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

int N, K, mindepth = 100010, cnt = 0;
double P, r;
vector<vector<int>> v;

void dfs(int index, int depth){
    int n = v[index].size();
    
    if(n == 0){
        if(mindepth == depth)
            cnt++;
        else if(depth < mindepth){
            mindepth = depth;
            cnt = 1;
        }
        return ;
    }
    
    for(int i = 0; i < n; i++)
        dfs(v[index][i], depth+1);
}

int main(void){
    scanf("%d %lf %lf", &N, &P, &r);
    
    v.resize(N);
    for(int i = 0; i < N; i++){
        scanf("%d", &K);
        v[i].resize(K);
        for(int j = 0; j < K; j++)
            scanf("%d", &v[i][j]);
    }
    
    dfs(0, 0);
    
    printf("%.4lf %d", P*pow(1+r*0.01, mindepth), cnt);
    
    return 0;
}
