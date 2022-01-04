#include<bits/stdc++.h>
using namespace std;

int N, M, src, dst, minDepth = INT_MAX, minT = INT_MAX, Distance, Time;
int disL[505], disT[505], len[505][505], tim[505][505];;
vector<int> path, ansL, ansT;
vector<vector<int> > preL, preT;

void dijstraLength(){
    int vis[505] = {0};
    fill(disL, disL+505, INT_MAX);
    disL[src] = 0;
    for(int i = 0; i < N; i++){
        int u = -1, minn = INT_MAX;
        for(int j = 0; j < N; j++){
            if(vis[j] == 0 && disL[j] < minn){
                u = j;
                minn = disL[j];
            }
        }
        if(u == -1)
            break;
        vis[u] = 1;
        for(int j = 0; j < N; j++){
            if(vis[j] == 0 && len[u][j] != INT_MAX/2){
                if(disL[j] > disL[u] + len[u][j]){
                    disL[j] = disL[u] + len[u][j];
                    preL[j].clear();
                    preL[j].push_back(u);
                }
                else if(disL[j] == disL[u] + len[u][j])
                    preL[j].push_back(u);
            }
        }
    }
    return ;
}

void dijstraTime(){
    int vis[505] = {0};
    fill(disT, disT+505, INT_MAX);
    disT[src] = 0;
    for(int i = 0; i < N; i++){
        int u = -1, minn = INT_MAX;
        for(int j = 0; j < N; j++){
            if(vis[j] == 0 && disT[j] < minn){
                u = j;
                minn = disT[j];
            }
        }
        if(u == -1)
            break;
        vis[u] = 1;
        for(int j = 0; j < N; j++){
            if(vis[j] == 0 && tim[u][j] != INT_MAX/2){
                if(disT[j] > disT[u] + tim[u][j]){
                    disT[j] = disT[u] + tim[u][j];
                    preT[j].clear();
                    preT[j].push_back(u);
                }
                else if(disT[j] == disT[u] + tim[u][j])
                    preT[j].push_back(u);
            }
        }
    }
    return ;
}

void dfsLength(int index, int cntTim, int sumL){
    if(index == src){
        if(minT > cntTim)
            minT = cntTim, ansL = path, Distance = sumL;
        return ;
    }
    
    int n = preL[index].size();
    for(int i = 0; i < n; i++){
        int j = preL[index][i];
        path.push_back(j);
        dfsLength(j, cntTim+tim[j][index], sumL+len[j][index]);
        path.pop_back();
    }
}

void dfsTime(int index, int depth, int sumT){
    if(index == src){
        if(depth < minDepth)
            minDepth = depth, ansT = path, Time = sumT;
        return ;
    }
    
    int n = preT[index].size();
    for(int i = 0; i < n; i++){
        int j = preT[index][i];
        path.push_back(j);
        dfsTime(j, depth+1, sumT+tim[j][index]);
        path.pop_back();
    }
}

int main(void){
    scanf("%d %d", &N, &M);
    
    fill(len[0], len[0]+505*505, INT_MAX/2);
    fill(tim[0], tim[0]+505*505, INT_MAX/2);
    for(int i = 0; i < M; i++){
        int v1, v2, one, l, t;
        scanf("%d %d %d %d %d", &v1, &v2, &one, &l, &t);
        len[v1][v2] = l, tim[v1][v2] = t;
        if(one == 0)
            len[v2][v1] = l, tim[v2][v1] = t;
    }
    
    scanf("%d %d", &src, &dst);
    
    preL.resize(N);
    preT.resize(N);
    
    dijstraLength();
    dfsLength(dst, 0, 0);
    
    dijstraTime();
    dfsTime(dst, 0, 0);
    
    int n1 = ansL.size(), n2 = ansT.size();
    if(ansL == ansT){
        printf("Distance = %d; Time = %d: ", Distance, Time, src);
        for(int i = n1-1; i >= 0; i--)
            printf("%d -> ", ansL[i]);
        printf("%d", dst);
    }
    else{
        printf("Distance = %d: ", Distance);
        for(int i = n1-1; i >= 0; i--)
            printf("%d -> ", ansL[i]);
        printf("%d\nTime = %d: ", dst, Time, src);
        for(int i = n2-1; i >= 0; i--)
            printf("%d -> ", ansT[i]);
        printf("%d", dst);
    }
    
    return 0;
}
