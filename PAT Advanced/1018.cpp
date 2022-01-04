#include<bits/stdc++.h>
using namespace std;

int Cmax, N, Sp, M, cntBike = -1;
int curBike[505], tim[505][505];
vector<vector<int>> pre;
vector<int> path, ans;

void dijstra(){
    int vis[505] = {0}, d[505];
    fill(d, d+505, INT_MAX/2);
    d[0] = 0;
    for(int i = 0; i <= N; i++){
        int u = -1, minn = INT_MAX;
        for(int j = 0; j <= N; j++){
            if(vis[j] == 0 && d[j] < minn){
                u = j;
                minn = d[j];
            }
        }
        if(u == -1)
            break;
        vis[u] = 1;
        for(int j = 0; j <= N; j++){
             if(vis[j] == 0 && tim[u][j] != INT_MAX/2){
                if(d[j] > d[u] + tim[u][j]){
                    d[j] = d[u] + tim[u][j];
                    pre[j].clear();
                    pre[j].push_back(u);
                }
                else if(d[j] == d[u] + tim[u][j])
                    pre[j].push_back(u);
             }
        }
    }
    return ;
}

void dfs(int index, int bike){
    if(index == 0){
        if(cntBike < bike){
            cntBike = bike;
            ans.assign(path.begin(), path.end());
        }
        return ;
    }
    
    bike += curBike[index]-Cmax/2;
    int n = pre[index].size();
    for(int i = 0; i < n; i++){
        path.push_back(pre[index][i]);
        dfs(pre[index][i], bike);
        path.pop_back();
    }
}

int main(void){
    scanf("%d %d %d %d", &Cmax, &N, &Sp, &M);
    for(int i = 1; i <= N; i++)
        scanf("%d", &curBike[i]);
    fill(tim[0], tim[0]+505*505, INT_MAX/2);
    for(int i = 0; i < M; i++){
        int s1, s2, t;
        scanf("%d %d %d", &s1, &s2, &t);
        tim[s1][s2] = tim[s2][s1] = t;
    }
    
    pre.resize(N+1);
    dijstra();
    
    dfs(Sp, 0);
    
    int need, back;
    if(cntBike >= 0)
        need = 0, back = cntBike;
    else
        need = -cntBike, back = 0;
    printf("%d ", need);
    for(int i = ans.size()-1; i >= 0; i--)
        printf("%d->", ans[i]);
    printf("%d %d", Sp, back);
    
    return 0;
}
