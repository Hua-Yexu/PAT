#include <iostream>
using namespace std;

int main(){
    float a[1001] = {0}, A;
    int K, N, cnt = 0;
    
    cin >> K;
    for(int i = 0; i < K; i++){
        cin >> N >> A;
        a[N] = A;
    }
    
    cin >> K;
    for(int i = 0; i < K; i++){
        cin >> N >> A;
        a[N] += A;
    }
    
    for(int i = 0; i < 1001; i++)
        if(a[i] != 0)
            cnt++;
    
    cout << cnt;
    for(int i = 1000; i >= 0; i--)
        if(a[i] != 0)
            printf(" %d %.1f", i, a[i]);
    
    return 0;
}
