#include <iostream>
using namespace std;

bool is_prime(int x){
    if(x <= 1)
        return false;
    for(int i = 2; i*i <= x; i++)
        if(x % i == 0)
            return false;
    return true;
}

int rev(int N, int D){
    int rev_N = 0;
    while(N){
        rev_N = rev_N*D + N % D;
        N /= D;
    }
    return rev_N;
}

int main(){
    int N, D;
    while(cin >> N && N >= 0){
        cin >> D;
        if(is_prime(N) && is_prime(rev(N, D)))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}
