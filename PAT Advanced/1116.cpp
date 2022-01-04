#include<bits/stdc++.h>
using namespace std;

bool isPrime(int x){
    if(x == 2 || x == 3)
        return true;
    for(int i = 2; i*i <= x; i++)
        if(x % i == 0)
            return false;
    return true;
}

int main(void){
    int N, K, id;
    map<int, int> m;
    
    scanf("%d", &N);
    for(int i = 1; i <= N; i++){
        scanf("%d", &id);
        m[id] = i;
    }
    
    scanf("%d", &K);
    for(int i = 0; i < K; i++){
        scanf("%d", &id);
        printf("%04d: ", id);
        if(m.find(id) == m.end())
            printf("Are you kidding?\n");
        else{
            if(m[id] == 1)
                printf("Mystery Award\n");
            else if(m[id] == -1)
                printf("Checked\n");
            else if(isPrime(m[id]) == true)
                printf("Minion\n");
            else
                printf("Chocolate\n");
            m[id] = -1;
        }
    }
    
    return 0;
}
