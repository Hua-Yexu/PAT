#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

long long f(long long a, long long b){
    return b == 0 ? a : f(b, a % b);
}

int main(void){
    int N;
    scanf("%d", &N);
    
    long long a1, b1, a2, b2, maxn;
    scanf("%lld/%lld", &a1, &b1);
    maxn = f(abs(a1), b1);
    a1 /= maxn;
    b1 /= maxn;
    for(int i = 1; i < N; i++){
        scanf("%lld/%lld", &a2, &b2);
        a1 = a1 * b2 + a2 * b1;
        b1 = b1 * b2;
        long long a = abs(a1);
        maxn = f(a, b1);
        a1 /= maxn;
        b1 /= maxn;
    }
    
    long long inte = a1 / b1;
    a1 = a1 % b1;
    if(inte != 0 && a1 != 0)
        printf("%lld %lld/%lld", inte, abs(a1), b1);
    else if(inte != 0 && a1 == 0)
        printf("%lld", inte);
    else if(inte == 0 && a1 != 0)
        printf("%lld/%lld", a1, b1);
    else
        printf("0");
    
    return 0;
}
