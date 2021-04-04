#include <cstdio>
using namespace std;

int main(void){
    int n1, n2;
    long s1[200002], s2[200002];

    scanf("%d", &n1);
    for(int i = 1; i <= n1; i++)
        scanf("%ld", &s1[i]);
    scanf("%d", &n2);
    for(int i = 1; i <= n2; i++)
        scanf("%ld", &s2[i]);

    int m = (n1 + n2 + 1) / 2, p1 = 1, p2 = 1, cnt = 0;
    long median;

    while(p1 <= n1 && p2 <= n2 && cnt++ < m)
        median = s1[p1] <= s2[p2] ? s1[p1++] : s2[p2++];
    
    if(cnt < m){
        if(p1 > n1)
            median = s2[m-n1];
        else if(p2 > n2)
            median = s1[m-n2];
    }

    printf("%ld", median);

    return 0;
}
