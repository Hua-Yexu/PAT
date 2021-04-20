#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s1, s2;
    cin >> s1;
    char digit[10][10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    
    int sum = 0;
    for(auto c : s1)
        sum += c-'0';
    
    s2 = to_string(sum);
    cout << digit[s2[0]-'0'];
    int len = s2.length();
    for(int i = 1; i < len; i++)
        cout << " " << digit[s2[i]-'0'];
    
    return 0;
}
