#include<bits/stdc++.h>
using namespace std;

int N, h[1001];
vector<int> isRoot, father;

int findFather(int x){
    int a = x;
    while(x != father[x])
        x = father[x];
    while(a != father[a]){
        int z = a;
        a = father[a];
        father[z] = x;
    }
    return x;
}

void Union(int a, int b){
    int faA = findFather(a);
    int faB = findFather(b);
    if(faA != faB)
        father[faA] = faB;
}

bool cmp(int a, int b){
    return a > b;
}

int main(void){
    scanf("%d", &N);
    
    isRoot.resize(N+1);
    father.resize(N+1);
    for(int i = 1; i <= N; i++)
        father[i] = i;
    for(int i = 1; i <= N; i++){
        int k, a;
        scanf("%d:", &k);
        for(int j = 0; j < k; j++){
            scanf("%d", &a);
            if(h[a] == 0) h[a] = i;
            Union(i, findFather(h[a]));//这里为什么是findFather？？
        }
    }
    
    for(int i = 1; i <= N; i++)
        isRoot[findFather(i)]++;//这里为什么是findfather？？？
    int cnt = 0;
    for(int i = 1; i <= N; i++)
        if(isRoot[i] != 0)
            cnt++;
    sort(isRoot.begin(), isRoot.end(), cmp);
    
    printf("%d\n", cnt);
    for(int i = 0; i < cnt; i++){
        if(i != 0) printf(" ");
        printf("%d", isRoot[i]);
    }
    
    return 0;
}
