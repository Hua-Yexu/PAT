#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

typedef struct{
    int hh;
    int mm;
    int ss;
}form;

int is_earlier(form temp, form first){
    if((temp.hh < first.hh) ||
       (temp.hh == first.hh && temp.mm < first.mm) ||
       (temp.hh == first.hh && temp.mm == first.mm && temp.ss < first.ss))
        return 1;
    return 0;
}

int is_later(form temp, form last){
    if((temp.hh > last.hh) ||
       (temp.hh == last.hh && temp.mm > last.mm) ||
       (temp.hh == last.hh && temp.mm == last.mm && temp.ss > last.ss))
        return 1;
    return 0;
}

int main(void){
    int M;
    string name, unlock, lock;
    form temp_in, temp_out, first, last;
    
    first.hh = 24; first.mm = 0; first.ss = 0;
    last.hh = last.mm = last.ss = 0;
    
    cin >> M;
    for(int i = 0; i < M; i++){
        cin >> name;
        scanf("%d:%d:%d %d:%d:%d", &temp_in.hh, &temp_in.mm, &temp_in.ss,
              &temp_out.hh, &temp_out.mm, &temp_out.ss);
        
        if(is_earlier(temp_in, first)){
            unlock = name;
            first = temp_in;
        }
        if(is_later(temp_out, last)){
            lock = name;
            last = temp_out;
        }
    }
    
    cout << unlock << " " << lock;
    
    return 0;
}
