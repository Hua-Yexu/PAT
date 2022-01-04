#include<bits/stdc++.h>
using namespace std;

int main(void){
    int N, M, a, b, c[100005], g[100005] = {0};
    set<int> s;
    
    fill(c, c+100005, 100000);
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d %d", &a, &b);
        c[a] = b, c[b] = a;
    }
    
    scanf("%d", &M);
    for(int i = 0; i < M; i++){
        scanf("%d", &a);
        g[a] = 1;
    }
    
    for(int i = 0; i < 100000; i++){
        if(g[i] == 1 && g[c[i]] != 1)
            s.insert(i);
    }
    
    printf("%d\n", s.size());
    for(auto it = s.begin(); it != s.end(); it++){
        if(it != s.begin())
            printf(" ");
        printf("%05d", *it);
    }
    
    return 0;
}
