#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

typedef struct{
    int id;
    string name;
    int grade;
}node;

bool cmp1(node a, node b){
    return a.id < b.id;
}

bool cmp2(node a, node b){
    if(a.name != b.name)
        return a.name < b.name;
    else
        return a.id < b.id;
}

bool cmp3(node a, node b){
    if(a.grade != b.grade)
        return a.grade < b.grade;
    else
        return a.id < b.id;
}

int main(void){
    int N, C;
    vector<node> data;
    
    cin >> N >> C;
    for(int i = 0; i < N; i++){
        node temp;
        cin >> temp.id >> temp.name >> temp.grade;
        data.push_back(temp);
    }
    
    if(C == 1)
        sort(data.begin(), data.end(), cmp1);
    else if(C == 2)
        sort(data.begin(), data.end(), cmp2);
    else
        sort(data.begin(), data.end(), cmp3);
    
    for(int i = 0; i < N; i++){
        printf("%06d", data[i].id);
        cout << " " << data[i].name << " " << data[i].grade << endl;
    }
    
    return 0;
}
