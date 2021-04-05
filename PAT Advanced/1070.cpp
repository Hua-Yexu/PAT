#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct{
    float ivt, pr, dv;
}node;

bool cmp(node a, node b){
    return a.dv > b.dv;
}

int main(void){
    int N, D;
    node data[1005];
    float max = 0;
    
    scanf("%d %d", &N, &D);
    for(int i = 0; i < N; i++)
        scanf("%f", &data[i].ivt);
    for(int i = 0; i < N; i++){
        scanf("%f", &data[i].pr);
        data[i].dv = data[i].pr / data[i].ivt;
    }
    
    sort(data, data+N, cmp);
    
    for(int i = 0; D && i < N; i++){
        if(D >= data[i].ivt){
            max += data[i].pr;
            D -= data[i].ivt;
        }
        else{
            max += D / data[i].ivt * data[i].pr;
            D = 0;
        }
    }
    
    printf("%.2f", max);
    
    return 0;
}
