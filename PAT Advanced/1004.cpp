#include <iostream>
#include <vector>
using namespace std;

vector<int> data[105];
int level[105] = {0};
int max_level = 0;

void dfs(int ID, int depth){
    if(data[ID].size() == 0){
        level[depth]++;
        if(max_level < depth)
            max_level = depth;
        return;
    }
    
    for(int i = 0, n = data[ID].size(); i < n; i++)
        dfs(data[ID][i], depth+1);
}

int main(void){
    int N, M;
    
    scanf("%d %d", &N, &M);
    for(int i = 0, ID, K; i < M; i++){
        scanf("%d %d", &ID, &K);
        for(int j = 0, son; j < K; j++){
            scanf("%d", &son);
            data[ID].push_back(son);
        }
    }
    
    dfs(1, 0);
    
    printf("%d", level[0]);
    for(int i = 1; i <= max_level; i++)
        printf(" %d", level[i]);
    
    return 0;
}
