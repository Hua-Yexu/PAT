#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a, int b){
    return a > b;
}

int main(void){
    int Nc, Np;
    
    scanf("%d", &Nc);
    vector<int> c(Nc);
    for(int i = 0; i < Nc; i++)
        scanf("%d", &c[i]);
    
    scanf("%d", &Np);
    vector<int> p(Np);
    for(int i = 0; i < Np; i++)
        scanf("%d", &p[i]);
    
    sort(c.begin(), c.end(), cmp);
    sort(p.begin(), p.end(), cmp);
    
    long max = 0;
    int n = min(Nc, Np), i;
    for(i = 0; i < n && c[i] > 0 && p[i] > 0; i++)
        max += c[i] * p[i];
    
    int j, jc = Nc-1, jp = Np-1;
    for(j = 0; j < n-i && c[jc] < 0 && p[jp] < 0; j++){
        max += c[jc] * p[jp];
        jc--;
        jp--;
    }
    
    printf("%ld", max);
    
    return 0;
}
