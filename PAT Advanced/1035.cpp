#include <iostream>
#include <string>
using namespace std;

struct node{
    string name, pass;
    bool flag = false;
};

bool modify(string &s){
    bool a = false;
    for(int i = 0; i < s.size(); i++)
        switch(s[i]){
            case '1': {s[i] = '@'; a = true; break;}
            case '0': {s[i] = '%'; a = true; break;}
            case 'l': {s[i] = 'L'; a = true; break;}
            case 'O': {s[i] = 'o'; a = true; break;}
        }
    return a;
}

int main(void){
    int N, M = 0;
    node data[1001];
    
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> data[i].name >> data[i].pass;
        if(modify(data[i].pass)){
            data[i].flag = true;
            M++;
        }
    }
    
    if(M){
        cout << M << endl;
        for(int i = 0; i < N; i++)
            if(data[i].flag)
                cout << data[i].name << " " << data[i].pass << endl;
    }
    else{
        if(N == 1)
            cout << "There is 1 account";
        else
            cout << "There are " << N << " accounts";
        cout << " and no account is modified";
    }

    return 0;
}
