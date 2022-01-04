#include<bits/stdc++.h>
using namespace std;

int main(void){
    int N, x;
    scanf("%d", &N);
    vector<int> v(N);
    for(int i = 0; i < N; i++){
        scanf("%d", &x);
        v[x] = i;
    }

    int a = 1, cnt = 0, temp;
    while(1){
        if(v[0] == 0){
            while(a < N && v[a] == a) a++;
            if(a == N) break;
            v[0] = v[a], v[a] = 0;
        }
        else
            temp = v[0], v[0] = v[v[0]], v[temp] = temp;
        cnt++;
    }

    printf("%d", cnt);

    return 0;
}
