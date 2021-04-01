#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void){
    int dot = 0;
    bool flag = true;
    string a, b;
    cin >> a;
    
    for(int i = a.length()-1; i >= 0; i--){
        b += (2 * (a[i]-'0')) % 10 + dot + '0';
        dot = (2 * (a[i]-'0')) / 10;
    }
    reverse(b.begin(), b.end());
    
    if(dot) 
        flag = false;
    else{
        for(int i = 0; i < a.length(); i++){
            int c = a.find(b[i]);
            if(c >= 0)
                a[c] = '.';
        }
        for(int i = 0; i < a.length(); i++)
            if(a[i] != '.')
                flag = false;
    }
    
    if(flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
   if(dot)
       cout << "1";
    cout << b;
    
    return 0;
}
