#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cctype>
#include <cstdio>
using namespace std;

typedef pair<string, int> PAIR;

bool cmp(PAIR a, PAIR b){
    if(a.second != b.second)
        return a.second > b.second;
    return a.first < b.first;
}

int main(void){
    map<string, int> mp;
    char c = '0';
    string s;

    while(c != '\n'){
        while(isalnum(c = getchar()))
            s += (c = tolower(c));
        if(s.size()){
            if(mp.find(s) == mp.end())
                mp[s] = 1;
            else
                mp[s]++;
            s = "";
        }
    }

    vector<PAIR> vp(mp.begin(), mp.end());
    sort(vp.begin(), vp.end(), cmp);

    cout << vp[0].first << " " << vp[0].second;

    return 0;
}
