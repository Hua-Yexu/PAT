#include <cstdio>
#include <map>
using namespace std;

int main(void){
    int M, N;
    scanf("%d %d", &M, &N);
    
    map<int, int> data;
    int temp;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            scanf("%d", &temp);
            if(++data[temp] > N*M/2){
                printf("%d", temp);
                return 0;
            }
        }
    }
    
    return 0;
}
