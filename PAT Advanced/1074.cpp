#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct form{
    int address, data, next;
};

int main(void){
    int add, N, K, cnt = 0;
    form seq[100005];
    vector<form> v;
    
    scanf("%d %d %d", &add, &N, &K);
    for(int i = 0; i < N; i++){
        form temp;
        scanf("%d %d %d", &temp.address, &temp.data, &temp.next);
        seq[temp.address] = temp;
    }
    
    for(cnt = 0; cnt < N && add != -1; cnt++){
        v.push_back(seq[add]);
        add = seq[add].next;
    }
    
    for(int i = 0; i+K <= cnt; i += K)
        reverse(v.begin()+i, v.begin()+i+K);
    
    for(int i = 0; i < cnt-1; i++)
        printf("%05d %d %05d\n", v[i].address, v[i].data, v[i+1].address);
    printf("%05d %d -1", v[cnt-1].address, v[cnt-1].data);
    
    return 0;
}
