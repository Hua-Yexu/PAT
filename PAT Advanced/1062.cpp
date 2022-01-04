#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct form{
    int ID, virtue, talent, total, tag;
};
/*
  tag = 1: sage
  tag = 2: nobleman
  tag = 3: fool man
  tag = 4: small man
  tag = 5: not be ranked
*/

bool cmp(form a, form b){
    if(a.total != b.total)
        return a.total > b.total;
    if(a.virtue != b.virtue)
        return a.virtue > b.virtue;
    return a.ID < b.ID;
}

int main(void){
    vector<form> data;
    int N, L, H, M;
    
    scanf("%d %d %d", &N, &L, &H);
    for(int i = 0; i < N; i++){
        form temp;
        scanf("%d %d %d", &temp.ID, &temp.virtue, &temp.talent);
        temp.total = temp.virtue + temp.talent;
        data.push_back(temp);
    }
    
    M = N;
    for(int i = 0; i < N; i++){
        if(data[i].virtue < L || data[i].talent < L){
            data[i].tag = 5;
            --M;
        }
        else if(data[i].virtue >= H && data[i].talent >= H)
            data[i].tag = 1;
        else if(data[i].virtue >= H)
            data[i].tag = 2;
        else if(data[i].virtue >= data[i].talent)
            data[i].tag = 3;
        else
            data[i].tag = 4;
    }
    
    sort(data.begin(), data.end(), cmp);
    
    printf("%d\n", M);
    for(int i = 1; i <= 4; i++){
        for(auto it = data.begin(); it != data.end(); it++)
            if(it->tag == i)
                printf("%d %d %d\n", it->ID, it->virtue, it->talent);
    }

    return 0;
}
