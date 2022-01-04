 #include<bits/stdc++.h>
using namespace std;

int N;
vector<int> pre, in, post;

void dfs(int root, int beg, int en){
    if(beg > en) return;
    int i = beg;
    while(in[i] != pre[root]) i++;
    dfs(root+1, beg, i-1);
    dfs(root+1+i-beg, i+1, en);
    post.push_back(pre[root]);
}

int main(void){
    int N;
    scanf("%d", &N);
    
    stack<int> s;
    for(int i = 0; i < 2*N; i++){
        string str;
        cin >> str;
        if(str == "Push"){
            int a;
            scanf("%d", &a);
            pre.push_back(a);
            s.push(a);
        }
        else{
            in.push_back(s.top());
            s.pop();
        }
    }
    
    dfs(0, 0, N-1);
    
    for(int i = 0; i < N; i++)
        printf("%d%c", post[i], i==N-1?'\n':' ');
    
    
    return 0;
}
