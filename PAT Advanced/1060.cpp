#include <iostream>
#include <string>
using namespace std;

int get_bit(string &s, int N){
    int bit;
    
    while(s.size() && s[0] == '0')
        s.erase(s.begin());
    
    if(s[0] == '.'){
        s.erase(s.begin());
        for(bit = 0; s[0] == '0'; bit++)
            s.erase(s.begin());
        if(s.size())
            bit = -bit;
        else
            bit = 0;
    }
    else
        for(bit = 0; bit < s.size(); bit++)
            if(s[bit] == '.'){
                s.erase(s.begin()+bit);
                break;
            }
    
    for(int i = s.size(); i < N; i++)
        s += "0";
    
    return bit;
}

void standard_form(string s, int bit, int N){
    cout << "0.";
    for(int i = 0; i < N; i++)
        cout << s[i];
    cout << "*10^" << bit;
}

int main(){
    int N, flag = 1;
    string A, B;
    cin >> N >> A >> B;

    int bit_A = get_bit(A, N);
    int bit_B = get_bit(B, N);

    if(bit_A == bit_B && A.compare(0, N, B, 0, N) == 0){
        cout << "YES ";
        standard_form(A, bit_A, N);
    }
    else{
        cout << "NO ";
        standard_form(A, bit_A, N);
        cout << " ";
        standard_form(B, bit_B, N);
    }

    return 0;
}
