#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

int N, index, maxdepth = 0, maxnum = 0;
double P, r;
vector<vector<int> > data;

void dfs(int index, int depth){
    if(depth > maxdepth){
        maxdepth = depth;
        maxnum = 1;
    }
    else if(depth == maxdepth)
        maxnum++;
    for(int i = 0; i < data[index].size(); i++)
        dfs(data[index][i], depth+1);
}

int main(void){
    scanf("%d %lf %lf", &N, &P, &r);
    data.resize(N);
    for(int i = 0; i < N; i++){
        int temp;
        scanf("%d", &temp);
        if(temp == -1)
            index = i;
        else
            data[temp].push_back(i);
    }
    
    dfs(index, 0);
    
    printf("%.2lf %d", P * pow(1+0.01*r, maxdepth), maxnum);

    return 0;
}
