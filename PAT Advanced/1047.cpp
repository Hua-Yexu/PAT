#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    vector<string> crs[2505];
    int N, K;
    
    scanf("%d %d", &N, &K);
    string name;
    int n, k;
    for(int i = 0; i < N; i++){
        cin >> name;
        scanf("%d", &n);
        for(int j = 0; j < n; j++){
            scanf("%d", &k);
            crs[k].push_back(name);
        }
    }
    
    for(int i = 1, s; i <= K; i++){
        s = crs[i].size();
        printf("%d %d\n", i, s);
        
        sort(crs[i].begin(), crs[i].end());
        
        for(int j = 0; j < s; j++)
            printf("%s\n", crs[i][j].c_str());
    }
    
    return 0;
}
