#include<bits/stdc++.h>
using namespace std;

int maxlevel = -1;
vector<vector<int>> t;
vector<int> vis, temp;
set<int> root;

void BFS(int index, int depth){
    if(depth >= maxlevel){
        if(depth > maxlevel)
            temp.clear();
        maxlevel = depth;
        temp.push_back(index);
    }
    vis[index] = 1;
    for(int i = 0; i < t[index].size(); i++)
        if(vis[t[index][i]] == 0)
            BFS(t[index][i], depth+1);
}

int main(void){
    int N;
    scanf("%d", &N);
    
    t.resize(N+1);
    for(int i = 0; i < N-1; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        t[a].push_back(b);
        t[b].push_back(a);
    }
    
    vis.resize(N+1);
    int cnt = 0;
    for(int i = 1; i <= N; i++)
        if(vis[i] == 0){
            BFS(i, 0);
            cnt++;
        }
    if(cnt >= 2)
        printf("Error: %d components\n", cnt);
    else{
        for(int i = 0; i < temp.size(); i++)
            root.insert(temp[i]);
        fill(vis.begin(), vis.end(), 0);
        temp.clear();
        maxlevel = -1;
        BFS(*root.begin(), 0);
        for(int i = 0; i < temp.size(); i++)
            root.insert(temp[i]);
        for(auto it = root.begin(); it != root.end(); it++)
            printf("%d\n", *it);
    }
    
    return 0;
}
