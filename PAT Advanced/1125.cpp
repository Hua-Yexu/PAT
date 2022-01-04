#include<bits/stdc++.h>
using namespace std;

int main(void){
    int N;
    scanf("%d", &N);
    
    vector<float> v(N);
    for(int i = 0; i < N; i++)
        scanf("%f", &v[i]);
    
    sort(v.begin(), v.end());
    
    float len = v[0];
    for(int i = 1; i < N-1; i++)
        if(len < v[i+1])
            len = (len + v[i]) / 2;
        else
            v[i+1] = (v[i] + v[i+1]) / 2;
    len = (len + v[N-1]) / 2;
    //if(len - (int)len >= 0.5) len++;
    
    printf("%d", (int)len);
    
    return 0;
}
