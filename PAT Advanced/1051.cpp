#include <cstdio>
#include <vector>
#include <stack>
using namespace std;

int main(void){
    int M, N, K;
    scanf("%d %d %d", &M, &N, &K);
    
    for(int i = 0; i < K; i++){
        stack<int> s;
        vector<int> v(N);
        for(int j = 0; j < N; j++)
            scanf("%d", &v[j]);

        int index = 0;
        for(int j = 1; j <= N; j++){
            s.push(j);
            if(s.size() > M)
                break;
            while(!s.empty() && s.top() == v[index]){
                s.pop();
                index++;
            }
        }
        
        printf("%s\n", index == N ? "YES" : "NO");
    }
    
    return 0;
}
