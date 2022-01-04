#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct node{
    int ID;
    string info[6];
};

int N;
vector<node> data;

bool cmp(node a, node b){
    return a.ID < b.ID;
}

bool find(int No, string query){
    bool isfind = false;
    for(int i = 0; i < N; i++){
        if((No != 3 && data[i].info[No] == query) || 
           (No == 3 && data[i].info[No].find(query) != string::npos)){
            printf("%07d\n", data[i].ID);
            isfind = true;
        }
    }
    return isfind;
}
           
int main(void){
    cin >> N;
    for(int i = 0; i < N; i++){
        node temp;
        scanf("%d\n", &temp.ID);
        for(int j = 1; j <= 5; j++)
            getline(cin, temp.info[j]);
        data.push_back(temp);
    }
    
    sort(data.begin(), data.end(), cmp);
    
    int M;
    cin >> M;
    for(int i = 0; i < M; i++){
        int No;
        string query;
        scanf("%d: ", &No);
        getline(cin, query);
        
        cout << No << ": " << query << endl;
        if(find(No, query) == false)
            cout << "Not Found" << endl;
    }
    
    return 0;
}
