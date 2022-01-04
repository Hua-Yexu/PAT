#include<bits/stdc++.h>
using namespace std;

int main(void){
    string s1[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
    string s2[13] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
    
    int N;
    scanf("%d", &N);
    getchar();
    for(int i = 0; i < N; i++){
        string s;
        getline(cin ,s);
        if(isdigit(s[0]) == true){
            int a = stoi(s);
            int b = a / 13, c = a % 13;
            if(b != 0 && c != 0) cout << s2[b] << " " << s1[c] << endl;
            else if(b == 0 && c != 0) cout << s1[c] << endl;
            else if(b != 0 && c == 0) cout << s2[b] << endl;
            else cout << s1[0] << endl;
        }
        else if(s.size() <= 4){
            int j = 0;
            while(j < 13 && s1[j] != s) j++;
            if(j < 13) printf("%d\n", j);
            else{
                j = 0;
                while(s2[j] != s) j++;
                printf("%d\n", j*13);
            }
        }
        else{
            string sa = s.substr(0, 3), sb = s.substr(4, s.size()-4);
            int j = 0, k = 0;
            while(s2[j] != sa) j++;
            while(s1[k] != sb) k++;
            printf("%d\n", j*13+k);
        }
    }
    
    return 0;
}
