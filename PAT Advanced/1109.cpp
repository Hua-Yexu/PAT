#include<bits/stdc++.h>
using namespace std;

struct form{
    string name;
    int height;
};

bool cmp(form a, form b){
    if(a.height != b.height)
        return a.height > b.height;
    return a.name < b.name;
}

int main(void){
    int N, K;
    scanf("%d %d", &N, &K);
    
    vector<form> data;
    for(int i = 0; i < N; i++){
        form temp;
        cin >> temp.name >> temp.height;
        data.push_back(temp);
    }
    
    sort(data.begin(), data.end(), cmp);
    
    vector<vector<string>> row(K);
    int n1 = N/K + N%K, n = N/K, p = n1/2;
    row[0].resize(n1);
    for(int i = 0, t = p, k = 2; i < n1; i++, k++){
        row[0][t] = data[i].name;
        t = p + k/2 * pow(-1, i+1);
    }
    p = n/2;
    for(int j = 1; j < K; j++){
        row[j].resize(n);
        for(int i = 0, t = p, k = 2; i < n; i++, k++){
            row[j][t] = data[n1+(j-1)*n+i].name;
            t = p + k/2 * pow(-1, i+1);
        }
    }
    
    for(int j = 0; j < K; j++){
        for(auto it = row[j].begin(); it != row[j].end(); it++){
            if(it != row[j].begin())
                printf(" ");
            cout << *it;
        }
        printf("\n");
    }
    
    return 0;
}
