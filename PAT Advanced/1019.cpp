#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    int N, b, i, flag = 1;
    int a[40] = {0};
    
    cin >> N >> b;
    
    for(i = 0; N != 0; i++){
        a[i] = N % b;
        N /= b;
    }
    
    for(int j = 0; j < i; j++)
        if(a[j] != a[i-1-j])
            flag = 0;
    
    printf("%s\n%d", flag ? "Yes" : "No", a[i-1]);
    for(int j = i-2; j >= 0; j--)
        cout << " " << a[j];
    
    return 0;
}
