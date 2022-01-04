#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

typedef struct{
    string data;
    int next;
    bool flag = false;
}node;

int main(){
    int word1, word2, n, add;
    node ipt[100010];
    
    cin >> word1 >> word2 >> n;
    for(int i = 0; i < n; i++){
        int add1, add2;
        string s;
        cin >> add1 >> s >> add2;
        ipt[add1].data = s;
        ipt[add1].next = add2;
    }
    
    for(add = word1; add != -1; add = ipt[add].next)
        ipt[add].flag = true;
    
    for(add = word2; add != -1; add = ipt[add].next)
        if(ipt[add].flag)
            break;
    
    if(add == -1)
        cout << add;
    else
        printf("%05d", add);
    
    return 0;
}
