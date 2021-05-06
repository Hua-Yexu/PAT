#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct node{
    string name, word;
    int MM, dd, HH, mm, time;
};

int N, rate[24], allrate = 0;

bool cmp(node a, node b){
    if(a.name != b.name)
        return a.name < b.name;
    return a.time < b.time;
}

float BillFromZero(node a){
    float bill = (a.dd-1) * allrate * 60;
    for(int j = 0; j < a.HH; j++)
        bill += rate[j] * 60;
    bill += a.mm * rate[a.HH];
    return bill / 100.0;
}

int main(void){
    
    for(int i = 0; i < 24; i++){
        scanf("%d", &rate[i]);
        allrate += rate[i];
    }
    scanf("%d", &N);
    
    vector<node> data(N);
    for(int i = 0; i < N; i++){
        cin >> data[i].name;
        scanf("%d:%d:%d:%d", &data[i].MM, &data[i].dd, &data[i].HH, &data[i].mm);
        data[i].time = data[i].dd*60*24 + data[i].HH*60 + data[i].mm;
        cin >> data[i].word;
    }
    
    sort(data.begin(), data.end(), cmp);
    
    map<string, vector<node> > custom;
    for(int i = 1; i < N; i++){
        if(data[i].name == data[i-1].name && data[i-1].word == "on-line" && data[i].word == "off-line"){
            custom[data[i-1].name].push_back(data[i-1]);
            custom[data[i].name].push_back(data[i]);
        }
    }
    
    for(auto it : custom){
        vector<node> a = it.second;
        cout << it.first;
        printf(" %02d\n", a[0].MM);
        float total = 0;
        for(int i = 1; i < a.size(); i += 2){
            float bill = BillFromZero(a[i]) - BillFromZero(a[i-1]);
            printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", a[i-1].dd, a[i-1].HH, a[i-1].mm, a[i].dd, a[i].HH, a[i].mm, a[i].time-a[i-1].time, bill);
            total += bill;
        }
        printf("Total amount: $%.2f\n", total);
    }
    
    return 0;
}
