#include<bits/stdc++.h>
using namespace std;

int main(void){
    int N, M, S, D;
    scanf("%d %d %d %d", &N, &M, &S, &D);
    
    vector<vector<int>> road(N, vector<int>(N)), cost(N, vector<int>(N));
    for(int i = 0; i < N; i++){
        fill(road[i].begin(), road[i].end(), INT_MAX/2);
        fill(cost[i].begin(), cost[i].end(), INT_MAX/2);
    }
    for(int i = 0; i < M; i++){
        int c1, c2, d, c;
        scanf("%d %d %d %d", &c1, &c2, &d, &c);
        road[c1][c2] = road[c2][c1] = d;
        cost[c1][c2] = cost[c2][c1] = c;// is it necessary???
    }
    
    vector<int> vis(N, 0), dis(N, INT_MAX/2), cst(N, INT_MAX/2), pre(N);
    dis[S] = 0;
    cst[S] = 0;
    pre[S] = -1;
    for(int i = 0; i < N; i++){
        int u = -1, minn = INT_MAX;
        for(int j = 0; j < N; j++){
            if(vis[j] == 0 && dis[j] < minn){
                u = j;
                minn = dis[j];
            }
        }
        
        if(u == -1)    break;
        vis[u] = 1;
        
        for(int j = 0; j < N; j++){
            if(dis[j] > dis[u] + road[u][j]){
                dis[j] = dis[u] + road[u][j];
                cst[j] = cst[u] + cost[u][j];
                pre[j] = u;
            }
            else if(dis[j] == dis[u] + road[u][j] && cst[j] > cst[u] + cost[u][j]){
                cst[j] = cst[u] + cost[u][j];
                pre[j] = u;
            }
        }
    }

    vector<int> path;
    for(int i = D; i != -1; i = pre[i])
        path.push_back(i);
    
    for(int i = path.size()-1; i >= 0; i--)
        printf("%d ", path[i]);
    printf("%d %d", dis[D], cst[D]);
    
    return 0;
}
