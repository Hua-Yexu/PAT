#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

typedef struct{
    int add, key = 1000000, next;
    bool is_valid = false;
}node;

bool cmp(node a, node b){
    if(a.is_valid && b.is_valid)
        return a.key < b.key;
    return a.is_valid > b.is_valid;
}

int main(){
    int n, head, cnt = 0;
    node data[100010];
    
    cin >> n >> head;
    for(int i = 0; i < n; i++){
        int add;
        cin >> add;
        data[add].add = add;
        cin >> data[add].key >> data[add].next;
    }
    
    for(int add = head; add != -1; add = data[add].next)
        if(data[add].key <= 100000 && data[add].key >= -100000){
            data[add].is_valid = true;
            cnt++;
        }
    
    if(cnt == 0)
        printf("0 -1");
    else{
        sort(data, data+100000, cmp);
    
        for(int i = 0; i < cnt-1; i++)
            data[i].next = data[i+1].add;
        data[cnt-1].next = -1;
    
        printf("%d %05d\n", cnt, data[0].add);
        for(int i = 0; i < cnt-1; i++)
            printf("%05d %d %05d\n", data[i].add, data[i].key, data[i].next);
        printf("%05d %d -1", data[cnt-1].add, data[cnt-1].key);
    }
    
    return 0;
}
