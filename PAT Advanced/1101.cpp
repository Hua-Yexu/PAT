#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    int N; 
    scanf("%d", &N);
    vector<int> v(N);
    for(int i = 0; i < N; i++)
        scanf("%d", &v[i]);
    
    vector<int> dpmax(N), dpmin(N);
    dpmax[0] = v[0];
    for(int i = 1; i < N; i++)
        dpmax[i] = max(dpmax[i-1], v[i]);
    dpmin[N-1] = v[N-1];
    for(int i = N-2; i >= 0; i--)
        dpmin[i] = min(dpmin[i+1], v[i]);
    
    vector<int> ans;
    for(int i = 0; i < N; i++)
        if(dpmax[i] == dpmin[i])
            ans.push_back(dpmax[i]);
    
    printf("%d\n", ans.size());
    for(auto it = ans.begin(); it != ans.end(); it++){
        if(it != ans.begin())
            printf(" ");
        printf("%d", *it);
    }
    printf("\n");
    
    return 0;
}
