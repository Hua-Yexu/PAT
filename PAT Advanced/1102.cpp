#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

struct node{
    int left = -1, right = -1;
};

int N, root;
vector<node> data;
vector<int> level, in;

void level_order(int index){
    queue<int> q;
    q.push(index);
    while(q.empty() == false){
        level.push_back(q.front());
        if(data[q.front()].left != -1)
            q.push(data[q.front()].left);
        if(data[q.front()].right != -1)
            q.push(data[q.front()].right);
        q.pop();
    }
}

void in_order(int index){
    if(index == -1)
        return ;
    
    in_order(data[index].left);
    in.push_back(index);
    in_order(data[index].right);
}

void print(vector<int> a){
    for(int i = 0; i < N; i++){
        if(i != 0)
            printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");
}

int main(void){
    scanf("%d", &N);
    data.resize(N);
    vector<int> tag(N, 0);
    
    for(int i = 0; i < N; i++){
        char a, b;
        getchar();
        scanf("%c", &a);
        getchar();
        scanf("%c", &b);
        
        if(a != '-'){
            data[i].right = a-'0';
            tag[a-'0'] = 1;
        }
        if(b != '-'){
            data[i].left = b-'0';
            tag[b-'0'] = 1;
        }
    }
    
    for(int i = 0; i < N; i++)
        if(tag[i] == 0){
            root = i;
            break;
        }
    
    level_order(root);
    in_order(root);
    
    print(level);
    print(in);
    
    return 0;
}
