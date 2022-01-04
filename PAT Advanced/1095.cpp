#include<bits/stdc++.h>
using namespace std;

struct node{
    string plt;
    int time, status, valid = 0;
};

bool cmp(node a, node b){
    return a.time < b.time;
}

int main(void){
    int N, K;
    scanf("%d %d", &N, &K);
    
    vector<node> v(N);
    map<string, int> sToi;
    map<int, string> iTos;
    for(int i = 0, j = 0; i < N; i++){
        string stts; int hh, mm, ss;
        cin >> v[i].plt;
        scanf("%d:%d:%d", &hh, &mm, &ss);
        cin >> stts;
        v[i].time = hh*60*60 + mm*60 + ss;
        if(stts == "in") v[i].status = 1;
        else v[i].status = 0;
        if(sToi.find(v[i].plt) == sToi.end())
            sToi[v[i].plt] = j, iTos[j++] = v[i].plt;
    }
    
    sort(v.begin(), v.end(), cmp);
    
    vector<int> q(K);
    for(int i = 0; i < K; i++){
        int hh, mm, ss;
        scanf("%d:%d:%d", &hh, &mm, &ss);
        q[i] = hh*60*60 + mm*60 + ss;
    }
    
    int n = sToi.size();
    vector<int> park(n);
    vector<vector<int>> record(n);
    for(int i = 0; i < N; i++){
        int m = sToi[v[i].plt];
        if(park[m] == 0 && v[i].status == 1){
            record[m].push_back(i);
            park[m] = 1;
        }
        else if(park[m] == 1 && v[i].status == 1){
            record[m].pop_back();
            record[m].push_back(i);
        }
        else if(park[m] == 1 && v[i].status == 0){
            v[record[m][record[m].size()-1]].valid = 1;
            v[i].valid = 1;
            record[m].push_back(i);
            park[m] = 0;
        }
    }
    
    int cnt = 0;
    for(int i = 0, j = 0, k = 0; i < 24*60*60; i++){
        while(v[j].time == i){
            if(v[j].valid == 1){
                if(v[j].status == 1) cnt++;
                else cnt--;
            }
            j++;
        }
        if(q[k] == i){
            printf("%d\n", cnt);
            k++;
        }
    }
    
    int maxtime = 0;
    vector<int> parkTime(n);
    for(int i = 0; i < n; i++){
        int k = record[i].size(); k -= k%2;
        for(int j = 0; j < k; j += 2)
            parkTime[i] += v[record[i][j+1]].time - v[record[i][j]].time;
        if(parkTime[i] > maxtime)
            maxtime = parkTime[i];
    }
    for(int i = 0, j = 0; i < n; i++)
        if(parkTime[i] == maxtime)
            cout << iTos[i] << " ";
    printf("%02d:%02d:%02d", maxtime/60/60, maxtime/60%60, maxtime%60);
    
    return 0;
}
