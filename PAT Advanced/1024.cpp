#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string add(string a, string b){
    string sum;
    int i, j, dot = 0;
    for(i = a.length()-1, j = 0; i >= 0; i--, j++){
        sum += (a[i]-'0' + b[i]-'0' + dot)%10 + '0';
        dot = (a[i]-'0' + b[i]-'0' + dot) >= 10 ? 1 : 0;
    }
    if(dot)
        sum += "1";
    reverse(sum.begin(), sum.end());
    return sum;
}

int main(void){
    string N;
    int K, i;
    
    cin >> N >> K;
    string reN = N;
    reverse(reN.begin(), reN.end());
    
    for(i = 0; i < K; i++){
        string reN = N;
        reverse(reN.begin(), reN.end());
        if(N == reN)
            break;
        N = add(N, reN);
    }
    
    cout << N << endl << i;
    
    return 0;
}
