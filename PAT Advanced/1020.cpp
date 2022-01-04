#include <cstdio>
#include <vector>
#include <map>
using namespace std;

int N;
vector<int> post, in;
map<int, int> level;

void dfs(int root, int left, int right, int index){
    if(left > right) return;
    level[index] = post[root];
    int i = left;
    while(in[i] != post[root] && i < right) i++;
    dfs(root-1-right+i, left, i-1, 2*index);
    dfs(root-1, i+1, right, 2*index+1);
}

int main(void){
    scanf("%d", &N);
    post.resize(N); in.resize(N);
    for(int i = 0; i < N; i++)scanf("%d", &post[i]);
    for(int i = 0; i < N; i++) scanf("%d", &in[i]);
    
    dfs(N-1, 0, N-1, 1);
    
    for(auto it = level.begin(); it != level.end(); it++){
        if(it != level.begin()) printf(" ");
        printf("%d", it->second);
    }
    
    return 0;
}
