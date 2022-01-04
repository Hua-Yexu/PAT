#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

typedef struct{
    string ID;
    int score;
    int final_rank;
    int loca_num;
    int local_rank;
}form;

bool cmp(form a, form b){
    if(a.score != b.score) 
        return a.score > b.score;
    else
        return a.ID < b.ID;
}

int main(void){
    int N, K, cnt = 0;
    cin >> N;
    
    form data[30001];
    
    for(int i = 1; i <= N; i++){
        cin >> K;
        
        for(int j = 0; j < K; j++){
            cin >> data[cnt].ID >> data[cnt].score;
            data[cnt++].loca_num = i;
        }
        
        sort(data+cnt-K, data+cnt, cmp);
        
        data[cnt-K].local_rank = 1;
        for(int j = 1; j < K; j++)
            if(data[cnt-K+j].score == data[cnt-K+j-1].score)
                data[cnt-K+j].local_rank = data[cnt-K+j-1].local_rank;
            else
                data[cnt-K+j].local_rank = j + 1;
    }
    
    sort(data, data+cnt, cmp);
    
    data[0].final_rank = 1;
    for(int i = 1; i < cnt; i++)
        if(data[i].score == data[i-1].score)
            data[i].final_rank = data[i-1].final_rank;
        else
            data[i].final_rank = i + 1;
    
    cout << cnt << endl;
    for(int i = 0; i < cnt; i++)
        cout << data[i].ID << " " << data[i].final_rank << " " 
             << data[i].loca_num << " " << data[i].local_rank << endl;
    
    return 0;
}
