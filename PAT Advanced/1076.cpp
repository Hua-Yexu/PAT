/*//dfs
#include<bits/stdc++.h>
using namespace std;

int N, L, K, vis[1005], lvl[1005], cnt;
vector<vector<int>> M;

void dfs(int i, int d){
    if(vis[i] == 0){
        cnt++;
        vis[i] = 1;
    }
    lvl[i] = d;
    int n = M[i].size();
    for(int j = 0; j < n && d < L; j++)
        if(lvl[M[i][j]] > d+1) //图中访问过的点也可能需要再次遍历，否则可能会丢失路径
                               //结点层数变小时才需改变层数重复遍历，不添加此条件case4将超时
            dfs(M[i][j], d+1);
}

int main(void){
    scanf("%d %d", &N, &L);
    
    M.resize(N+1);
    for(int i = 1; i <= N; i++){
        int m, a;
        scanf("%d", &m);
        for(int j = 0; j < m; j++){
            scanf("%d", &a);
            M[a].push_back(i);
        }
    }
    
    scanf("%d", &K);
    for(int i = 0; i < K; i++){
        int a;
        scanf("%d", &a);
        fill(vis, vis+1005, 0);
        fill(lvl, lvl+1005, L+10);
        vis[a] = 1;
        cnt = 0;
        
        dfs(a, 0);
        
        printf("%d\n", cnt);
    }
    
    return 0;
}*/

//BFS
//不知道为什么有segmentation fault
/*
#include<bits/stdc++.h>
using namespace std;

int N, L, K, vis[1005], lvl[1005];
vector<vector<int>> M;

int bfs(int root){
    int cnt = 0;
    queue<int> q;
    q.push(root);
    fill(vis, vis+1005, 0);
    vis[root] = 1;
    lvl[root] = 0;
    while(q.empty() == false){
        int i = q.front(), n = M[i].size();
        for(int j = 0; j < n; j++){
            if(vis[M[i][j]] == 0 && lvl[i] < L){
                q.push(M[i][j]);
                vis[M[i][j]] = 1;
                lvl[M[i][j]] = lvl[i] + 1;
                cnt++;
            }
        }
        q.pop();
    }
    return cnt;
}

int main(void){
    scanf("%d %d", &N, &L);
    
    M.resize(N);
    for(int i = 1; i <= N; i++){
        int m, a;
        scanf("%d", &m);
        for(int j = 0; j < m; j++){
            scanf("%d", &a);
            M[a].push_back(i);
        }
    }
    
    scanf("%d", &K);
    for(int i = 0; i < K; i++){
        int a;
        scanf("%d", &a);
        printf("%d\n", bfs(a));
    }
    
    return 0;
}*/

#include<bits/stdc++.h>
using namespace std;

int N, L, K;
vector<vector<int>> M;

int bfs(int root){
    int cnt = 0, vis[1010] = {0}, lvl[1010];
    queue<int> q;
    q.push(root);
    vis[root] = 1;
    fill(lvl, lvl+1010, 1010);
    lvl[root] = 0;
    while(q.empty() == false){
        int u = q.front(), n = M[u].size();
        q.pop();
        for(int i = 0; i < n && lvl[u] < L; i++){
            int v = M[u][i];
            if(vis[v] == 0){
                q.push(v);
                vis[v] = 1;
                lvl[v] = lvl[u] + 1;
                cnt++;
            }
        }
    }
    return cnt;
}

int main(void){
    scanf("%d %d", &N, &L);
    
    M.resize(N+1);
    for(int i = 1; i <= N; i++){
        int m, a;
        scanf("%d", &m);
        for(int j = 0; j < m; j++){
            scanf("%d", &a);
            M[a].push_back(i);
        }
    }
    
    scanf("%d", &K);
    for(int i = 0; i < K; i++){
        int a;
        scanf("%d", &a);
        printf("%d\n", bfs(a));
    }
    
    return 0;
}
