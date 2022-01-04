#include<bits/stdc++.h>
using namespace std;

int main(void){
    int N, E = 1, m[100005];
    
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", &m[i]);
    
    sort(m, m+N);
    for(int i = N-1; i >= 0; i--){
        if(m[i] > E) E++;
        else break;
    }
    
    printf("%d", E-1);
    
    return 0;
}
