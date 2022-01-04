#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

int N, K, P, vsumMax = 0;
vector<int> p, v, ans;

void initpow(){
    for(int i = 0, t; t < N; i++){
        t = pow(i, P);
        p.push_back(t);
    }
}

void dfs(int index, int sum, int vsum){
    if(v.size() == K){
        if(sum == N && vsum > vsumMax){
            ans = v;
            vsumMax = vsum;
        }
        return ;
    }
    
    if(sum > N)
        return ;
    
    for(int i = index; i > 0; i--){
        v.push_back(i);
        dfs(i, sum+p[i], vsum+i);
        v.pop_back();
    }
}

int main(void){
    scanf("%d %d %d", &N, &K, &P);
    
    initpow();
    
    dfs(p.size()-1, 0, 0);
    
    if(ans.empty())
        printf("Impossible");
    else{
        printf("%d = %d^%d", N, ans[0], P);
        for(int i = 1; i < K; i++)
            printf(" + %d^%d", ans[i], P);
    }
    
    return 0;
}
