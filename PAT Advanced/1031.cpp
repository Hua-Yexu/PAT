#include <iostream>
#include <string>
using namespace std;

int main(void){
    string s;
    cin >> s;
    
    int N = s.size();
    int n1 = N/3 + (N%3 ? 1 : 0);
    int n2 = N + 2 - n1*2;
    
    for(int i = 0; i < n1-1; i++){
        cout << s[i];
        for(int j = 0; j < n2-2; j++)
            cout << " ";
        cout << s[N-1-i] << endl;
    }
    cout << s.substr(n1-1, n2);
    
    return 0;
}
