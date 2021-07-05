#include <iostream>
#include <string>
using namespace std;

int main(void){
    string owner, Eva;
    cin >> owner >> Eva;
    
    int n1 = owner.size(), s1[130] = {0};
    for(int i = 0; i < n1; i++)
        s1[owner[i]]++;
    
    int n2 = Eva.size(), less;
    for(int i = 0; i < n2; i++){
        if(s1[Eva[i]] <= 0)
            less++;
        s1[Eva[i]]--;
    }
    
    if(less)
        printf("No %d", less);
    else
        printf("Yes %d", n1 - n2);
    
    return 0;
}
