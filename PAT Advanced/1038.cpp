#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string a, string b){//组合最小
    return a+b < b+a;
}

int main(void){
    vector<string> data;
    int N;
    string num;
    
    cin >> N;
    for(int i = 0; i < N; i++){
        string temp;
        cin >> temp;
        data.push_back(temp);
    }
    
    sort(data.begin(), data.end(), cmp);
    
    for(int i = 0; i < N; i++){
        num += data[i];
    }
    
    int i;
    for(i = 0; num[i] == '0' && i < N; i++);
    if(i < N)
        cout << num.substr(i);
    else
        cout << "0";
    
    return 0;
}
