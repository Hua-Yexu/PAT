#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct{
    string name, gender, id;
    int grade;
}node;

bool cmp(node a, node b){
    if(a.gender == b.gender)
        return a.grade > b.grade;
    else
        return a.gender < b.gender;
}

int main(void){
    int N;
    vector<node> data;
    
    cin >> N;
    for(int i = 0; i < N; i++){
        node temp;
        cin >> temp.name >> temp.gender >> temp.id >> temp.grade;
        data.push_back(temp);
    }
    
    sort(data.begin(), data.end(), cmp);
    
    if(data[0].gender == "F")
        cout << data[0].name << " " << data[0].id << endl;
    else
        cout << "Absent" << endl;
    if(data[N-1].gender == "M")
        cout << data[N-1].name << " " << data[N-1].id << endl;
    else
        cout << "Absent" << endl;
    if(data[0].gender == "F" && data[N-1].gender == "M")
        cout << data[0].grade-data[N-1].grade;
    else
        cout << "NA";
    
    return 0;
}
