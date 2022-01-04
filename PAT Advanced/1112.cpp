#include<bits/stdc++.h>
using namespace std;

bool cntSame(string s, int i, int k){
    for(int j = 1; j < k; j++)
        if(s[i] != s[i+j])
            return false;
    return true;
}

int main(void){
    int k, tag[128] = {0}, n;
    string s;
    vector<char> v;
    
    cin >> k >> s;
    
    n = s.size();
    for(int i = 0; i < n; i++){
        auto it = find(v.begin(), v.end(), s[i]);
        if(i < n-k+1 && cntSame(s, i, k) == true && tag[s[i]] == 0){
            if(it == v.end())
                v.push_back(s[i]);
            i += k-1;
        }
        else{
            if(it != v.end())
                v.erase(it);
            tag[s[i]] = 1;
        }
    }
    
    for(int i = 0; i < v.size(); i++)
        cout << v[i];
    cout << endl;
    for(int i = 0; i < n; i++){
        cout << s[i];
        if(tag[s[i]] == 0)
            i += k-1;
    }
    
    return 0;
}
