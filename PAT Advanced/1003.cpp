#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int main(void){
    int N, M, C1, C2;
    int team[505] = {0}, road[505][505], d[505], cnt[505] = {0}, sum[505] = {0}; 
    bool visit[505] = {false};
    
    fill(road[0], road[0]+505*505, INT_MAX/2);
    fill(d, d+505, INT_MAX/2);
    cin >> N >> M >> C1 >> C2;
    for(int i = 0; i < N; i++)
        cin >> team[i];
    for(int i = 0; i < M; i++){
        int a, b, c;
        cin >> a >> b >> c;
        road[a][b] = road[b][a] = c;
    }
    
    sum[C1] = team[C1];
    d[C1] = 0;
    cnt[C1] = 1;
    for(int i = 0, now = C1; i < N; i++){
        int minn = INT_MAX/2;
        visit[now] = true;
        for(int j = 0; j < N; j++){
            if(d[now] + road[now][j] < d[j]){
                d[j] = d[now] + road[now][j];
                sum[j] = sum[now] + team[j];
                cnt[j] = cnt[now];
            }
            else if(d[now] + road[now][j] == d[j]){
                cnt[j] += cnt[now];
                if(sum[j] < sum[now] + team[j])
                    sum[j] = sum[now] + team[j];
            }
        }
        
        bool flag = false;
        for(int next = 0; next < N; next++){
            if(visit[next] == false && d[next] < minn){
                minn = d[next];
                now = next;
                flag = true;
            }
        }
        if(flag == false)
            break;
    }
    
    cout << cnt[C2] << " " << sum[C2];
    
    return 0;
}
