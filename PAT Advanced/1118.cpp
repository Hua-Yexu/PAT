#include<bits/stdc++.h>
using namespace std;

int father[10000];

int find(int x){
    while(father[x] != x)
        x = father[x];
    return x;
}

void Union(int a, int b){
    int faA = find(a);
    int faB = find(b);
    if(faA > faB) father[faA] = faB;
    else father[faB] = faA;
}

int main(void){
    for(int i = 0; i < 10000; i++)
        father[i] = i;
    
    int N;
    set<int> bird;
    
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        int k, a, b;
        scanf("%d %d", &k, &a);
        bird.insert(a);
        for(int j = 1; j < k; j++){
            scanf("%d", &b);
            bird.insert(b);
            Union(a, b);
        }
    }
    
    set<int> tree;
    for(auto it = bird.begin(); it != bird.end(); it++)
        tree.insert(find(*it));
    
    printf("%d %d\n", tree.size(), bird.size());
    
    int Q;
    scanf("%d", &Q);
    for(int i = 0; i < Q; i++){
        int b1, b2;
        scanf("%d %d", &b1, &b2);
        if(find(b1) == find(b2))
            printf("Yes\n");
        else
            printf("No\n");
    }
    
    return 0;
}
