#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct node{
    string name;
    int age, net;
};

bool cmp(node a, node b){
    if(a.net != b.net)
        return a.net > b.net;
    if(a.age != b.age)
        return a.age < b.age;
    if(a.name != b.name)
        return a.name < b.name;
}

int main(void){
    int N, K, M, Amin, Amax;
    node data[100005];
    
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        node temp;
        cin >> temp.name >> temp.age >> temp.net;
        data[i] = temp;
    }
    
    sort(data, data+N, cmp);
    
    for(int i = 1; i <= K; i++){
        cin >> M >> Amin >> Amax;
        int cnt = 0;
        cout << "Case #" << i << ":" << endl;
        for(int j = 0; j < N; j++){
            if(data[j].age >= Amin && data[j].age <= Amax){
                cout << data[j].name << " " << data[j].age << " " << data[j].net << endl;
                if(++cnt == M)
                    break;
            }
        }
        if(cnt == 0)
            cout << "None" << endl;
    }
    
    return 0;
}
