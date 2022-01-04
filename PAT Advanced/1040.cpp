#include <iostream>
using namespace std;

string s;

bool symmetric(int left, int right){
    while(left <= right){
        if(s[left++] != s[right--])
            return false;
    }
    return true;
}

int main(void){
    getline(cin ,s);
    
    int longest = 0;
    for(int i = 0; i+longest < s.size(); i++){
        for(int j = s.size()-1; j > i+longest; j--){
            if(symmetric(i, j)){
                longest = j - i;
                break;
            }
        }
    }
    
    cout << longest+1;
    
    return 0;
}
