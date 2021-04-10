#include <iostream>
using namespace std;

int main(void){
    int bet[100005], cnt[10005] = {0};
    int N;
    
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> bet[i];
        cnt[bet[i]]++;
    }
    
    for(int i = 0; i < N; i++)
        if(cnt[bet[i]] == 1){
            cout << bet[i];
            return 0;
        }
    cout << "None";
    
    return 0;
}
