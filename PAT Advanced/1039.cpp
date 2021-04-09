#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int gethash(string s){
    int n = 0;
    for(int i = 0; i < 3; i++)
        n = 26*n + s[i]-'A';
    return n = n*10 + s[3]-'0';
}

bool cmp(int a, int b){
    return a < b;
}

int main(void){
    int N, K;
    vector<int> data[26*26*26*10+10];
    
    cin >> N >> K;
    for(int i = 0; i < K; i++){
        int ci, k;
        cin >> ci >> k;
        for(int j = 0; j < k; j++){
            string s;
            cin >> s;
            data[gethash(s)].push_back(ci);
        }
    }
    
    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        int index = gethash(s), size = data[index].size();
        
        sort(data[index].begin(), data[index].end(), cmp);
        
        cout << s << " " << size;
        for(int j = 0; j < size; j++)
            cout << " " << data[index][j];
        cout << endl;
    }
    
    return 0;
}
