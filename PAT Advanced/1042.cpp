#include <iostream>
using namespace std;

int main(void){
    int N, a[60], b[60], order[60];
    
    cin >> N;
    for(int i = 1; i <= 54; i++){
        cin >> order[i];
        b[i] = i;
    }
    
    for(int i = 0; i < N; i++){
        for(int j = 1; j <= 54; j++)
            a[j] = b[j];
        for(int j = 1; j <= 54; j++)
            b[order[j]] = a[j];
    }
    
    char c[6] = "SHCDJ";
    for(int i = 1; i <= 54; i++){
        if(i != 1)
            cout << " ";
        if(b[i]%13 == 0)
            cout << c[b[i]/13-1] << 13;
        else
            cout << c[b[i]/13] << b[i]%13;
    }
    
    return 0;
}
