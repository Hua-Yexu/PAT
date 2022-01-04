#include<bits/stdc++.h>
using namespace std;

int main(void){
    int N;
    scanf("%d", &N);
    
    vector<int> v(N);
    for(int i = 0; i < N; i++)
        scanf("%d", &v[i]);
    
    sort(v.begin(), v.end());
    
    int n = N/2, s = 0;
    for(int i = 0; i < n; i++)
        s += v[N-1-i] - v[i];
    if(N % 2)
        s += v[n];
    
    printf("%d %d", N%2, s);
    
    return 0;
}
