#include<bits/stdc++.h>
using namespace std;

int main(void){
    int N;
    scanf("%d", &N);
    
    set<int> id;
    for(int i = 0; i < N; i++){
        int sum = 0;
        string s;
        cin >> s;
        for(int j = 0; j < s.size(); j++)
            sum += s[j] - '0';
        id.insert(sum);
    }
    
    printf("%d\n", id.size());
    for(auto it = id.begin(); it != id.end(); it++){
        if(it != id.begin())
            printf(" ");
        printf("%d", *it);
    }
    
    return 0;
}
