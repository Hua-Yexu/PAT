//并查集
#include<bits/stdc++.h>
using namespace std;

int N, K, cntName = 1, head, cntMem, wSum;
int edge[2005][2005], vert[2005], vis[2005];
map<string, int> sToi, ans;
map<int, string> iTos;

int toNum(string s){
    if(sToi[s] == 0){
        sToi[s] = cntName;
        iTos[cntName] = s;
        return cntName++;
    }
    else
        return sToi[s];
}

void dfs(int i){
    vis[i] = 1;
    if(vert[i] > vert[head])
        head = i;
    cntMem++;
    for(int j = 1; j < cntName; j++){
        if(edge[i][j] > 0){
            wSum += edge[i][j];
            edge[i][j] = edge[j][i] = 0;
            if(vis[j] == 0)
                dfs(j);
        }
    }
}

int main(void){
    scanf("%d %d", &N, &K);

    for(int i = 0; i < N; i++){
        string s1, s2;
        int t;
        cin >> s1 >> s2 >> t;
        int a1 = toNum(s1), a2 = toNum(s2);
        edge[a1][a2] += t, edge[a2][a1] += t;
        vert[a1] += t, vert[a2] += t;
    }
    
    for(int i = 1; i < cntName; i++){
        if(vis[i] == 0){
            head = i, cntMem = 0, wSum = 0;
            dfs(i);
            if(cntMem > 2 && wSum > K)
                ans[iTos[head]] = cntMem;
        }
    }
    
    printf("%d\n", ans.size());
    for(auto it = ans.begin(); it != ans.end(); it++)
        cout << it->first << " " << it->second << endl;
    
    return 0;
}
