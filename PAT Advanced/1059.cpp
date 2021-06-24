#include <cstdio>
#include <map>
using namespace std;

//判断函数可用一个记录是否是素数的数组代替
bool is_prime(long a){
    if(a == 2 || a == 3)
        return true;
    for(long i = 2; i * i <= a; i++)
        if(a % i == 0)
            return false;
    return true;
}

int main(void){
    long int a;
    map<long, int> m;
    
    scanf("%ld", &a);
    
    printf("%ld=", a);
    if(a == 1)
        printf("1");
    
    for(long i = 2, b = a; i <= a && b != 1; i++){
        if(a % i == 0 && is_prime(i)){
            while(b % i == 0){
                b = b / i;
                m[i]++;
            }
        }
    }
    
    for(auto it = m.begin(); it != m.end(); it++){
        if(it != m.begin())
            printf("*");
        printf("%ld", it->first);
        if(it->second > 1)
            printf("^%d", it->second);
    }
    
    return 0;
}
