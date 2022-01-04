#include<bits/stdc++.h>
using namespace std;

struct node{
    int left = -1, right = -1;
};

int N, root, maxpos = 0, last_node;
vector<node> data;

void dfs(int index, int pos){
    if(index == -1)
        return ;
    
    maxpos = max(maxpos, pos);
    if(pos == N)
        last_node = index;
    
    dfs(data[index].left, pos*2);
    dfs(data[index].right, pos*2+1);
}

int main(void){
    scanf("%d", &N);
    
    data.resize(N);
    vector<int> tag(N, 0);
    for(int i = 0; i < N; i++){
        string a, b;
        cin >> a >> b;
        if(a != "-")    {data[i].left = stoi(a); tag[data[i].left] = 1;}
        if(b != "-")    {data[i].right = stod(b); tag[data[i].right] = 1;}
    }
    
    for(int i = 0; i < N; i++){
        if(tag[i] == 0){
            root = i;
            break;
        }
    }
    
    dfs(root, 1);
    
    if(maxpos == N)
        printf("YES %d", last_node);
    else
        printf("NO %d", root);
    
    return 0;
}
