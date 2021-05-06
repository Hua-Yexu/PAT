//测试点五：银行会服务完所有17点前开始排队的顾客
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;

#define OPEN 8*60*60
#define CLOSE 17*60*60

struct node{
    int T, P;
};

bool cmp(node a, node b){
    return a.T < b.T;
}

int main(void){
    int N, K, sum = 0;
    scanf("%d %d", &N, &K);
    
    vector<node> data;
    for(int i = 0; i < N; i++){
        int HH, MM, SS;
        node temp;
        scanf("%d:%d:%d %d", &HH, &MM, &SS, &temp.P);
        if((temp.T = HH*60*60 + MM*60 + SS) <= CLOSE){
            temp.P *= 60;
            data.push_back(temp);
        }
    }
    sort(data.begin(), data.end(), cmp);
    
    priority_queue<int, vector<int>, greater<int> > win; //小顶堆
    for(int i = 0; i < K; i++)
        win.push(OPEN);
    
    int cnt = data.size();
    for(int i = 0; i < cnt; i++){
        if(win.top() <= data[i].T){
            win.push(data[i].T + data[i].P);
            win.pop();
        }
        else{
            sum += win.top() - data[i].T;
            win.push(win.top() + data[i].P);
            win.pop();
        }
    }
    
    printf("%.1f", cnt == 0 ? 0 : 1.0*sum/cnt/60);
    
    return 0;
}
