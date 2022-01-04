#include<bits/stdc++.h>
using namespace std;

struct node{
    int left, right, value;
};

int N, m = 0;
vector<node> v;
vector<int> key;

void dfs(int index){
    if(index == -1) return;
    dfs(v[index].left);
    v[index].value = key[m++];
    dfs(v[index].right);
}

void bfs(){
    queue<int> q;
    q.push(0);
    printf("%d", v[0].value);
    while(q.empty() == false){
        int i = q.front();
        q.pop();
        if(i) printf(" %d", v[i].value);
        if(v[i].left != -1) q.push(v[i].left);
        if(v[i].right != -1) q.push(v[i].right);
    }
}

int main(void){
    scanf("%d", &N);
    v.resize(N); key.resize(N);
    for(int i = 0; i < N; i++) scanf("%d %d", &v[i].left, &v[i].right);
    for(int i = 0; i < N; i++) scanf("%d", &key[i]);
    
    sort(key.begin(), key.end());
    dfs(0);
    bfs();
    
    return 0;
}
