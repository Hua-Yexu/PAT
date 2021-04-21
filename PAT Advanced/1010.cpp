#include <iostream>
#include <cctype>
#include <string>
#include <algorithm>
using namespace std;

long to_num(string s, long r){
    int l = s.size();
    long sum = 0;
    for(int i = 0; i < l; i++)
        sum = sum*r + (isdigit(s[i]) ? s[i]-'0' : s[i]-'a'+10);
    return sum;
}

long find_rb(long a, string sb){
    char c = *max_element(sb.begin(), sb.end());
    long min_rb = (isdigit(c) ? c-'0' : c-'a'+10) + 1;
    long max_rb = max(a, min_rb);
    long b, mid;
    
    while(min_rb <= max_rb){
        mid = (max_rb + min_rb) / 2;
        b = to_num(sb, mid);
        if(a == b)
            return mid;
        if(b > a || b < 0)
            max_rb = mid - 1;
        else
            min_rb = mid + 1;
    }
    
    return -1;
}

int main(void){
    string N1, N2, sa, sb;
    long tag, ra, rb;
    
    cin >> N1 >> N2 >> tag >> ra;
    
    sa = tag == 1 ? N1 : N2;
    sb = tag == 1 ? N2 : N1;
    
    rb = find_rb(to_num(sa, ra), sb);
    
    if(rb != -1)
        cout << rb;
    else
        cout << "Impossible";
    
    return 0;
}
