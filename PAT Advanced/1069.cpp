#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(char a, char b){
    return a > b;
}

int main(void){
    int n1, n2, n3 = -1;
    string s, s1, s2;
    
    cin >> s;
    if(s.size() == 4 && s[0] == s[1] && s[1] == s[2] && s[2] == s[3]){
        cout << s << " - " << s << " = 0000" << endl;
        return 0;  
    }
    
    while(n3 != 6174){
        sort(s.begin(), s.end(), cmp);
        s.insert(s.end(), 4-s.size(), '0');
        n1 = stoi(s, 0, 10);
        reverse(s.begin(), s.end());
        n2 = stoi(s, 0, 10);
        n3 = n1 - n2;
        printf("%04d - %04d = %04d\n", n1, n2, n3);
        s = to_string(n3);
    }
    
    return 0;
}
