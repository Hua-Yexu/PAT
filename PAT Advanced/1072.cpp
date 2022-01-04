#include<bits/stdc++.h>
using namespace std;

int N, M, K, ans = -1, dist[1020][1020], vis[1020], d[1020];
double Ds, sumD = INT_MAX, minD = 0;

int sToi(string s){
    if(s[0] == 'G')
        return stoi(s.substr(1, s.size()-1)) + N;
    return stoi(s);
}

void dijstra(int root){
    fill(vis, vis+1020, 0);
    fill(d, d+1020, INT_MAX/2);
    d[root] = 0;
    for(int i = 1; i <= N+M; i++){
        int u = -1, minn = INT_MAX;
        for(int j = 1; j <= N+M; j++){
            if(vis[j] == 0 && d[j] < minn){
                u = j;
                minn = d[j];
            }
        }
        if(u == -1)
            break;
        vis[u] = 1;
        for(int j = 1; j <= N+M; j++){
            if(vis[j] == 0 && dist[u][j] != INT_MAX/2)
                d[j] = min(d[j], d[u] + dist[u][j]);
        }
    }
    return;
}

int main(void){
    scanf("%d %d %d %lf", &N, &M, &K, &Ds);
    
    fill(dist[0], dist[0]+1020*1020, INT_MAX/2);
    for(int i = 0; i < K; i++){
        string s1, s2;
        int dis, p1, p2;
        cin >> s1 >> s2 >> dis;
        p1 = sToi(s1), p2 = sToi(s2);
        dist[p1][p2] = dist[p2][p1] = dis;
    }
    
    for(int i = 1; i <= M; i++){
        dijstra(N+i);
        double sum = 0, mind = INT_MAX;
        bool flag = true;
        for(int j = 1; j <= N; j++){
            if(d[j] > Ds)    {flag = false; break;}
            sum += d[j];
            mind = min(mind, (double)d[j]);
        }
        if(flag){
            if(minD < mind)
                ans = i, minD = mind, sumD = sum;
            else if(minD == mind && sum < sumD)
                ans = i, sumD = sum;
        }
    }
    
    if(ans != -1)
        printf("G%d\n%.1lf %.1lf", ans, minD, sumD/N);
    else
        printf("No Solution");
    
    return 0;
}
