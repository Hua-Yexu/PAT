#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main(void){
    string s;
    cin >> s;
    
    if(s[0] == '-')
        putchar('-');
    s.erase(s.begin());
    s.erase(1, 1);
    
    auto posE = s.find('E');
    int e = stoi(s.substr(posE+2), 0, 10);
    if(s[posE+1] == '+'){
        if(posE == e+1)
            cout << s.substr(0, posE);
        else if(posE > e){
            cout << s.substr(0, e+1);
            printf(".");
            cout << s.substr(e+1, posE-e-1);
        }
        else{
            cout << s.substr(0, posE);
            for(int i = 1; i < e; i++)
                printf("0");
        }
    }
    else{
        printf("0.");
        for(int i = 1; i < e; i++)
            printf("0");
        cout << s.substr(0, posE);
    }
    
    return 0;
}
