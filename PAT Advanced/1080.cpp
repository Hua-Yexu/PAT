#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct form{
    int id, GE, GI, finall, choice[6];
};

bool cmp(form a, form b){
    if(a.finall != b.finall)
        return a.finall > b.finall;
    return a.GE > b.GE;
}

int main(void){
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);
    
    vector<form> data(N);
    vector<int> quota(M), lastrank(M);
    vector<vector<int> > admit(M);
    
    for(int i = 0; i < M; i++)
        scanf("%d", &quota[i]);
    for(int i = 0; i < N; i++){
        data[i].id = i;
        scanf("%d %d", &data[i].GE, &data[i].GI);
        data[i].finall = (data[i].GE + data[i].GI) / 2;
        for(int j = 0; j < K; j++)
            scanf("%d", &data[i].choice[j]);
    }
    
    sort(data.begin(), data.end(), cmp);
    
    for(int i = 0, rank = 1; i < N; i++){
        if(!(i > 0 && data[i].finall == data[i-1].finall && data[i].GE == data[i-1].GE))
            rank++;
        for(int j = 0; j < K; j++){
            int scnum = data[i].choice[j];
            if(admit[scnum].size() < quota[scnum] || lastrank[scnum] == rank){
                admit[scnum].push_back(data[i].id);
                lastrank[scnum] = rank;
                break;
            }
        }
    }
    
    for(int i = 0; i < M; i++){
        sort(admit[i].begin(), admit[i].end());
        for(int j = 0; j < admit[i].size(); j++){
            if(j > 0)
                printf(" ");
            printf("%d", admit[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
