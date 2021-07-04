#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main(void){
    string s1, s2, result;
    cin >> s1 >> s2;
    
    int p1 = 0, p2 = 0, n1 = s1.size(), n2 = s2.size();
    bool h[130] = {false};
    while(p1 < n1){
        if(s1[p1] == s2[p2])
            p1++, p2++;
        else{
            char c = toupper(s1[p1]);
            if(h[c] == false){
                h[c] = true;
                result += c;
            }
            p1++;
        }
    }
    
    cout << result;
    
    return 0;
}
