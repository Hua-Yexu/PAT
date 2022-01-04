#include<bits/stdc++.h>
using namespace std;

int N, K, maxHpp = 0, cntPath = 0;
double maxAveHpp = 0;
int hpp[210], vis[210], d[210], cost[210][210];
map<string, int> sToi;
map<int, string> iTos;
vector<vector<int>> pre;
vector<int> path, ans;

void dijstra(){
    fill(d, d+210, INT_MAX/2);
    d[0] = 0;
    for(int i = 0; i < N; i++){
        int u = -1, minn = INT_MAX;
        for(int j = 0; j < N; j++){
            if(vis[j] == 0 && d[j] < minn){
                u = j;
                minn = d[j];
            }
        }
        if(u == -1)
            break;
        vis[u] = 1;
        for(int j = 0; j < N; j++){
            if(vis[j] == 0 && cost[u][j] != INT_MAX/2){
                if(d[j] > d[u] + cost[u][j]){
                    d[j] = d[u] + cost[u][j];
                    pre[j].clear();
                    pre[j].push_back(u);
                }
                else if(d[j] == d[u] + cost[u][j])
                    pre[j].push_back(u);
            }
        }
    }
    return ;
}

void dfs(int index, int depth, int sumHpp){
    if(index == 0){
        if(sumHpp > maxHpp){
            maxHpp = sumHpp;
            maxAveHpp = 1.0*sumHpp/depth;
            ans = path;
        }
        else if(sumHpp == maxHpp && 1.0*sumHpp/depth > maxAveHpp){
            maxAveHpp = 1.0*sumHpp/depth;
            ans = path;
        }
        cntPath++;
        return ;
    }
    
    for(int i = 0; i < pre[index].size(); i++){
        int j = pre[index][i];
        path.push_back(j);
        dfs(j, depth+1, sumHpp+hpp[j]);
        path.pop_back();
    }
}

int main(void){
    scanf("%d %d", &N, &K);
    
    string root;
    cin >> root;
    sToi[root] = 0, iTos[0] = root;
    
    for(int i = 1; i < N; i++){
        string s;
        cin >> s >> hpp[i];
        sToi[s] = i, iTos[i] = s;
    }
    
    fill(cost[0], cost[0]+210*210, INT_MAX/2);
    for(int i = 0; i < K; i++){
        string s1, s2;
        int c, c1, c2;
        cin >> s1 >> s2 >> c;
        c1 = sToi[s1], c2 = sToi[s2];
        cost[c1][c2] = cost[c2][c1] = c;
    }
    
    pre.resize(N+1);
    dijstra();
    
    int rom = sToi["ROM"];
    dfs(rom, 0, hpp[rom]);
    
    int n = ans.size();
    printf("%d %d %d %d\n", cntPath, d[rom], maxHpp, maxHpp/n);
    for(int i = n-1; i >= 0; i--)
        cout << iTos[ans[i]] << "->";
    cout << "ROM";
    return 0;
}
