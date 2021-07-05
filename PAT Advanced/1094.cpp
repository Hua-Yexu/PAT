#include <cstdio>
#include <vector>
#include <map>
using namespace std;

int N, M;
vector<vector<int> > data;
map<int, int> levelcnt;

void dfs(int ID, int level){
    levelcnt[level]++;
    for(int i = 0; i < data[ID].size(); i++)
        dfs(data[ID][i], level+1);
}

int main(void){
    scanf("%d %d", &N, &M);
    
    data.resize(N+1);
    int root;
    for(int i = 0; i < M; i++){
        int ID, K;
        scanf("%d %d", &ID, &K);
        data[ID].resize(K);
        for(int j = 0; j < K; j++)
            scanf("%d", &data[ID][j]);
    }
    
    dfs(1, 1);
    
    int maxnum = 0, maxlevel;
    for(auto it = levelcnt.begin(); it != levelcnt.end(); it++){
        if(maxnum < it->second){
            maxnum = it->second;
            maxlevel = it->first;
        }
    }
    printf("%d %d", maxnum, maxlevel);
    
    return 0;
}
