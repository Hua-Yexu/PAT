#include <cstdio>
#include <vector>
#include <set>
#include <cstdlib>
using namespace std;

struct node{
    int add, key, next;
};

int main(void){
    int p, N;
    scanf("%d %d", &p, &N);
    
    vector<node> data(100010);
    for(int i = 0; i < N; i++){
        node temp;
        scanf("%d %d %d", &temp.add, &temp.key, &temp.next);
        data[temp.add] = temp;
    }
    
    set<int> s;
    vector<node> ans, rev;
    while(p != -1){
        if(s.find(abs(data[p].key)) == s.end()){
            ans.push_back(data[p]);
            s.insert(abs(data[p].key));
        }
        else
            rev.push_back(data[p]);
        p = data[p].next;
    }
    
    int n1 = ans.size(), n2 = rev.size();
    for(int i = 0; i < n1-1; i++)
        printf("%05d %d %05d\n", ans[i].add, ans[i].key, ans[i+1].add);
    printf("%05d %d -1\n", ans[n1-1].add, ans[n1-1].key);
    for(int i = 0; i < n2-1; i++)
        printf("%05d %d %05d\n", rev[i].add, rev[i].key, rev[i+1].add);
    if(n2 > 0)
        printf("%05d %d -1\n", rev[n2-1].add, rev[n2-1].key);
    
    return 0;
}
