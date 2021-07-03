//Quadratic probing :二次方探法
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

bool IsPrime(int m){
    if(m <= 1)
        return false;
    if(m == 2 || m == 3)
        return true;
    for(int i = 2; i*i <= m; i++)
        if(m % i == 0)
            return false;
    return true;
}

int FindPrime(int m){
    while(IsPrime(m) == false)
        m++;
    return m;
}

int main(void){
    int M, N;
    vector<int> pos;
    
    scanf("%d %d", &M, &N);
    
    M = FindPrime(M);
    for(int i = 0; i < N; i++){
        int a, p;
        scanf("%d", &a);
        p = a % M;
        if(find(pos.begin(), pos.end(), p) != pos.end()){
            p = -1;
            for(int step = 1; step < M; step++){
                int idx = (a + step * step) % M;
                if(find(pos.begin(), pos.end(), idx) == pos.end()){
                    p = idx;
                    break;
                }
            }
        }
        pos.push_back(p);
    }
    
    for(int i = 0; i < N; i++){
        if(i != 0)
            printf(" ");
        if(pos[i] == -1)
            printf("-");
        else
            printf("%d", pos[i]);
    }
    
    return 0;
}
