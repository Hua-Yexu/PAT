#include <cstdio>
#include <vector>
#include <set>
using namespace std;

int main(void){
    vector<set<int> > data;
    int N, M, temp, K, a, b;
    float Nc = 0, Nt;
    
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &M);
        set<int> s;
        for(int j = 0; j < M; j++){
            scanf("%d", &temp);
            s.insert(temp);
        }
        data.push_back(s);
    }
    
    scanf("%d", &K);
    for(int i = 0; i < K; i++){
        scanf("%d %d", &a, &b);
        for(auto it = data[a-1].begin(); it != data[a-1].end(); it++){
            if(data[b-1].find(*it) != data[b-1].end())
                Nc = Nc + 1;
        }
        Nt = data[a-1].size() + data[b-1].size() - Nc;
        printf("%.1f\%\n", Nc / Nt * 100);
    }
    
    return 0;
}
