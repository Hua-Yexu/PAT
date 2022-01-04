#include <cstdio>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

struct nodetable{
    int time = 8*60*60, cnt = 0, tag = 0;
};

struct nodeplayer{
    int arr, ser, play, wait, tag;
};

int N, K, M;
vector<nodetable> table;
vector<nodeplayer> cus;

bool cmp(nodeplayer a, nodeplayer b){
    return a.arr < b.arr;
}

int findtable(void){
    int index, VIPindex = -1, mintime = INT_MAX;
    for(int i = 0; i < K; i++){
        if(table[i].time <= cus[0].arr){
            if(cus[0].tag == 0)
                return i;
            if(cus[0].tag == 1){
                if(VIPindex == -1)
                    VIPindex = i;
                if(table[VIPindex].tag == 0 && table[i].tag == 1)
                    VIPindex = i;
            }
        }
        if(table[i].time < mintime){
            index = i;
            mintime = table[i].time;
        }
        if(table[i].time == mintime && table[index].tag == 0 && cus[0].tag == 1)
            index = i;
    }
    if(mintime >= 21*60*60)
        return -1;
    if(VIPindex != -1)
        return VIPindex;
    return index;
}

/*int findtable(void){
    int mintime = INT_MAX, index = 0;
    for(int i = 0; i < K; i++){
        if(table[i].time <= cus[0].arr)
            return i;
        if(table[i].time < mintime){
            index = i;
            mintime = table[i].time;
        }
    }
    if(mintime >= 21*60*60)
        return -1;
    return index;
}*/

int findVIPcus(int time){
    int i = 0, n = cus.size();
    while(i < n && cus[i].arr <= time){
        if(cus[i].tag == 1)
            return i;
        i++;
    }
    return 0;
}

int main(void){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        int hh, mm, ss;
        nodeplayer temp;
        scanf("%d:%d:%d %d %d", &hh, &mm, &ss, &temp.play, &temp.tag);
        temp.arr = hh*60*60 + mm*60 + ss;
        temp.play *= 60;
        if(temp.play > 2*60*60)
            temp.play = 2*60*60;
        cus.push_back(temp);
    }
    scanf("%d %d", &K, &M);
    table.resize(K);
    for(int i = 0; i < M; i++){
        int a;
        scanf("%d", &a);
        table[a-1].tag = 1;
    }
    
    sort(cus.begin(), cus.end(), cmp);
    
    for(int i = 0; i < N; i++){
        if(cus[0].arr >= 21*60*60)
            break;
        int c = 0, t = findtable();
        if(t == -1)
            break;
        if(table[t].tag == 1 && cus[c].tag == 0)
            c = findVIPcus(table[t].time);
        
        if(cus[c].arr < table[t].time)
            cus[c].ser = table[t].time;
        else
            cus[c].ser = cus[c].arr;
        cus[c].wait = cus[c].ser - cus[c].arr;
        table[t].time = cus[c].ser + cus[c].play;
        table[t].cnt++;
        int w = cus[c].wait / 60;
        if(cus[c].wait % 60 >= 30)
            w++;
        
        printf("%02d:%02d:%02d %02d:%02d:%02d %d\n", cus[c].arr/3600, cus[c].arr/60%60, cus[c].arr%60, 
               cus[c].ser/3600, cus[c].ser/60%60, cus[c].ser%60, w);
        
        cus.erase(cus.begin()+c);
    }
    
    for(int i = 0; i < K; i++){
        if(i != 0)
            printf(" ");
        printf("%d", table[i].cnt);
    }
    
    return 0;
}
