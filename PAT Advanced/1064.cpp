//我好菜。。
#include<bits/stdc++.h>
using namespace std;

struct node{
    int left = -1, right = -1, value;
};

int N;
vector<node> v;

bool cmp(node a, node b){
    return a.value < b.value;
}

int getRoot(int beg, int en){
    if(beg > en) return -1;
    int n = en - beg + 1, i = 0;
    while(pow(2, i)-1 < n) i++;
    if(i == 1) return beg;
    int last = n - pow(2, i-1) + 1;
    if(last > pow(2, i-2))
        last = pow(2, i-2);
    return beg + pow(2, i-2) -1 + last;
}

void CBT(int index, int beg, int en){
    if(beg >= en) return;
    
    int a = getRoot(beg, index-1);
    v[index].left = a;
    CBT(a, beg, index-1);
    
    int b = getRoot(index+1, en);
    v[index].right = b;
    CBT(b, index+1, en);
}

void BFS(int root){
    queue<int> q;
    q.push(root);
    int cnt = 0;
    while(q.empty() == false){
        if(cnt++ != 0) printf(" ");
        int i = q.front();
        printf("%d", v[i].value);
        q.pop();
        if(v[i].left != -1) q.push(v[i].left);
        if(v[i].right != -1) q.push(v[i].right);
    }
}

int main(void){
    scanf("%d", &N);
    v.resize(N);
    for(int i = 0; i < N; i++)
        scanf("%d", &v[i].value);
    
    sort(v.begin(), v.end(), cmp);
    
    int root = getRoot(0, N-1);
    CBT(root, 0, N-1);
    
    BFS(root);
    
    return 0;
}
