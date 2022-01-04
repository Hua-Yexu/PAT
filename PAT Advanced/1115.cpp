#include<bits/stdc++.h>
using namespace std;

struct node{
    int left = -1, right = -1, value, level;
};

int N, maxlevel = 0;
vector<node> v;

void buildBST(int i){
    int j = 0, k, tag;
    while(j != -1){
        k = j;
        if(v[i].value <= v[j].value)
            j = v[j].left, tag = 0;
        else
            j = v[j].right, tag = 1;
    }
    if(tag == 0) v[k].left = i;
    else         v[k].right = i;
}

void dfs(int index, int depth){
    v[index].level = depth;
    maxlevel = max(maxlevel, depth);
    if(v[index].left != -1)
        dfs(v[index].left, depth+1);
    if(v[index].right != -1)
        dfs(v[index].right, depth+1);
}

int main(void){
    scanf("%d", &N);
    
    v.resize(N);
    scanf("%d", &v[0].value);
    for(int i = 1; i < N; i++){
        scanf("%d", &v[i].value);
        buildBST(i);
    }
    
    dfs(0, 1);
    
    int n1 = 0, n2 = 0;
    for(int i = 0; i < N; i++){
        if(v[i].level == maxlevel) n1++;
        if(v[i].level == maxlevel-1) n2++;
    }
    printf("%d + %d = %d", n1, n2, n1+n2);
    
    return 0;
}
