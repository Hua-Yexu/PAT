#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void){
    int N;
    cin >> N;
    
    getchar();
    string s1, s2;
    getline(cin, s1);
    while(getline(cin, s2)){
        string temp;
        int cnt = 0, i = s1.size()-1, j = s2.size()-1;
        while(i >= 0 && j >= 0 && s1[i--] == s2[j--])
            cnt++;
        if(cnt == 0){
            cout << "nai" ;
            return 0;
        }
        s1 = s2.substr(s2.size()-cnt, cnt);
    }
    cout << s1;
    
    return 0;
}
