#include<bits/stdc++.h>
using namespace std;

int main(void){
    int M, N, S;
    vector<string> v;
    set<string> win;
    
    scanf("%d %d %d", &M, &N, &S);
    v.resize(M+2);
    for(int i = 1; i <= M; i++)
        cin >> v[i];
    
    for(int i = 1; i <= M; i += N){
        while(i <= M && win.find(v[i]) != win.end())
            i++;
        if(i > M) break;
        win.insert(v[i]);
        cout << v[i] << endl;
    }
    if(win.size() == 0)
        printf("Keep going...");
    
    return 0;
}
