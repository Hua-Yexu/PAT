#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct form{
    string name, id;
    int grade;
};

bool cmp(form a, form b){
    return a.grade > b.grade;
}

int main(void){
    int N;
    cin >> N;
    
    vector<form> data(N);
    for(int i = 0; i < N; i++)
        cin >> data[i].name >> data[i].id >> data[i].grade;
    
    sort(data.begin(), data.end(), cmp);
    
    int grade1, grade2, cnt = 0;
    cin >> grade1 >> grade2;
    for(int i = 0; i < N; i++){
        if(data[i].grade >= grade1 && data[i].grade <= grade2){
            cout << data[i].name << " " << data[i].id << endl;
            cnt++;
        }
    }
    if(cnt == 0)
        cout << "NONE";
    
    return 0;
}
