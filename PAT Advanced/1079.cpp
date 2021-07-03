#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

struct form{
    int K, level;
    double amount;
    vector<int> next;
};

vector<form> data;
int N;
double P, r, sum = 0;

void dfs(int index, int depth){
    if(data[index].K == 0){
        sum += pow((1+0.01*r), depth) * P * data[index].amount;
        return;
    }
    data[index].level = depth;
    for(int i = 0; i < data[index].K; i++)
        dfs(data[index].next[i], depth+1);
}

int main(void){
    scanf("%d %lf %lf", &N, &P, &r);
    for(int i = 0; i < N; i++){
        form temp;
        scanf("%d", &temp.K);
        if(temp.K == 0)
            scanf("%lf", &temp.amount);
        else{
            temp.next.resize(temp.K);
            for(int j = 0; j < temp.K; j++)
                scanf("%d", &temp.next[j]);
        }
        data.push_back(temp);
    }
    
    dfs(0, 0);
    
    printf("%.1lf", sum);
    
    return 0;
}
