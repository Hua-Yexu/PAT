#include<bits/stdc++.h>
using namespace std;

struct node{
    int left = -1, right = -1, value;
};

void build(int index, vector<node> &T){
    int i = 0, j, tag;
    while(i != -1){
        j = i;
        if(T[i].value > T[index].value)
            i = T[i].left, tag = 0;
        else
            i = T[i].right, tag = 1;
    }
    if(tag == 0) T[j].left = index;
    else         T[j].right = index;
}

void dfsPre(int index, vector<node> T, vector<int> &vec){
    vec.push_back(T[index].value);
    if(T[index].left != -1)
        dfsPre(T[index].left, T, vec);
    if(T[index].right != -1)
        dfsPre(T[index].right, T, vec);
}

void dfsPost(int index, vector<node> T){
    if(T[index].left != -1)
        dfsPost(T[index].left, T);
    if(T[index].right != -1)
        dfsPost(T[index].right, T);
    printf("%d", T[index].value);
    if(index != 0)
        printf(" ");
}
int main(void){
    int N;
    scanf("%d", &N);
    
    vector<int> v(N), vBST, vMBST;
    vector<node> BST(N), MBST(N);
    scanf("%d", &v[0]);
    BST[0].value = MBST[0].value = v[0];
    for(int i = 1; i < N; i++){
        scanf("%d", &v[i]);
        BST[i].value = MBST[i].value = v[i];
        build(i, BST);
    }
    for(int i = 0; i < N; i++){
        MBST[i].left = BST[i].right;
        MBST[i].right = BST[i].left;
    }
    
    dfsPre(0, BST, vBST);
    if(v == vBST){
        printf("YES\n");
        dfsPost(0, BST);
        return 0;
    }
    
    dfsPre(0, MBST, vMBST);
    if(v == vMBST){
        printf("YES\n");
        dfsPost(0, MBST);
        return 0;
    }
    
    printf("NO");
    return 0;
}
