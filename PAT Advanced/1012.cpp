#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

typedef struct{
    string ID;
    int C, C_rank;
    int M, M_rank;
    int E, E_rank;
    float A;
    int A_rank;
}form;

bool cmp_C(form data1, form data2){
    return data1.C > data2.C;
}

bool cmp_M(form data1, form data2){
    return data1.M > data2.M;
}

bool cmp_E(form data1, form data2){
    return data1.E > data2.E;
}

bool cmp_A(form data1, form data2){
    return data1.A > data2.A;
}

int main(){
    int N, M;
    cin >> N >> M;

    form data[2001];
    for(int i = 0; i < N; i++){
        cin >> data[i].ID >> data[i].C >> data[i].M >> data[i].E;
        data[i].A = (data[i].C + data[i].M + data[i].E) * 1.0 / 3;
    }

    sort(data, data+N, cmp_C);
    for(int i = 0; i < N; i++){
        if(i >= 1 && data[i].C == data[i-1].C)
            data[i].C_rank = data[i-1].C_rank;
        else
            data[i].C_rank = i + 1;
    }

    sort(data, data+N, cmp_M);
    for(int i = 0; i < N; i++){
        if(i >= 1 && data[i].M == data[i-1].M)
            data[i].M_rank = data[i-1].M_rank;
        else
            data[i].M_rank = i + 1;
    }

    sort(data, data+N, cmp_E);
    for(int i = 0; i < N; i++){
        if(i >= 1 && data[i].E == data[i-1].E)
            data[i].E_rank = data[i-1].E_rank;
        else
            data[i].E_rank = i + 1;
    }

    sort(data, data+N, cmp_A);
    for(int i = 0; i < N; i++){
        if(i >= 1 && data[i].A == data[i-1].A)
            data[i].A_rank = data[i-1].A_rank;
        else
            data[i].A_rank = i + 1;
    }

    for(int i = 0; i < M; i++){
        string stu;
        cin >> stu;
        int j;
        for(j = 0; j < N; j++)
            if(stu == data[j].ID)
                break;
        if(j < N){
            if(data[j].A_rank <= data[j].C_rank && data[j].A_rank <= data[j].M_rank && data[j].A_rank <= data[j].E_rank)
                cout << data[j].A_rank << " A" << endl;
            else if(data[j].C_rank < data[j].A_rank && data[j].C_rank <= data[j].M_rank && data[j].C_rank <= data[j].E_rank)
                cout << data[j].C_rank << " C" << endl;
            else if(data[j].M_rank < data[j].A_rank && data[j].M_rank < data[j].C_rank && data[j].M_rank <= data[j].E_rank)
                cout << data[j].M_rank << " M" << endl;
            else if(data[j].E_rank < data[j].A_rank && data[j].E_rank < data[j].M_rank && data[j].E_rank < data[j].C_rank)
                cout << data[j].E_rank << " E" << endl;
        }
        else
            cout << "N/A" << endl;
    }

    return 0;
}
