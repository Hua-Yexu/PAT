#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    int N, M, L;
    scanf("%d %d", &N, &M);
    
    vector<int> Eva(210, 0);
    for(int i = 0; i < M; i++){
        int a;
        scanf("%d", &a);
        Eva[a] = i+1;
    }
    
    scanf("%d", &L);
    vector<int> stripe;
    for(int i = 0; i < L; i++){
        int a;
        scanf("%d", &a);
        if(Eva[a])
            stripe.push_back(a);
    }
    
    int n = stripe.size(), maxL = -1;
    vector<int> cnt(n, 1);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(Eva[stripe[j]] <= Eva[stripe[i]])
                cnt[i] = max(cnt[i], cnt[j]+1);
        }
        maxL = max(maxL, cnt[i]);
    }

    printf("%d", maxL);
    
    return 0;
}
