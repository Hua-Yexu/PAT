#include <iostream>
#include <string>
using namespace std;

int main(void){
    string s1, s2;
    
    getline(cin, s1);
    getline(cin, s2);
    
    for(int i = 0; i < s1.size(); i++){
        if(s2.find(s1[i]) == string::npos)
            cout << s1[i];
    }
    
    return 0;
}
