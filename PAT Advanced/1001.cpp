#include <iostream>
using namespace std;

int main(void){
    int a, b;
    cin >> a >> b;
    
    string s = to_string(a+b);
    
    int len = s.length();
    for(int i = 0, j = 0; i < len; i++, j++){
        cout << s[i];
        if(s[i] == '-') 
            continue;
        if((len-i-1) % 3 == 0 & len-i-1 != 0)
            cout << ",";
    }
    
    return 0;
}
