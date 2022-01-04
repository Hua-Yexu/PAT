#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, S;
vector<int> w;
vector<vector<int>> tree, ans;

void dfs(int index, int sum, vector<int> p){
    int n = tree[index].size();
    p.push_back(w[index]);
    sum += w[index];
    if(n == 0){
        if(S == sum)
            ans.push_back(p);
        return;
    }
    for(int i = 0; i < tree[index].size(); i++)
        dfs(tree[index][i], sum, p);
}

bool cmp(vector<int> a, vector<int> b){
    int n1 = a.size(), n2 = b.size();
    for(int i = 0; i < n1 && i < n2; i++){
        if(a[i] != b[i])
            return a[i] > b[i];
    }
    return n1 > n2;
}

int main(void){
    scanf("%d %d %d", &N, &M, &S);
    
    w.resize(N);
    for(int i = 0; i < N; i++)
        scanf("%d", &w[i]);
    
    tree.resize(N);
    for(int i = 0; i < M; i++){
        int ID, K;
        scanf("%d %d", &ID, &K);
        tree[ID].resize(K);
        for(int j = 0; j < K; j++)
            scanf("%d", &tree[ID][j]);
    }
    
    dfs(0, 0, {});
    
    sort(ans.begin(), ans.end(), cmp);
    
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            if(j != 0)
                printf(" ");
            printf("%d", ans[i][j]);
        }
        printf("\n");
    }
    
    return 0;
    
}
