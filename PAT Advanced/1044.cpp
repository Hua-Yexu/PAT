/*二分法
#include <cstdio>
#include <vector>
#include <map>
#include <climits>
using namespace std;

int N, M;
vector<int> S;

int find(int i){
    int left = i, right = N;
    while(left <= right){
        int mid = (left + right) / 2;
        if(S[mid] - S[i-1] < M)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left;
}

int main(void){
    scanf("%d %d", &N, &M);
    S.resize(N+10);
    for(int i = 1; i <= N; i++){
        scanf("%d", &S[i]);
        S[i] += S[i-1];
    }
    
    map<int, int> m1, m2;
    int minn = INT_MAX;
    for(int i = 1; i <= N; i++){
        int j = find(i), sum = S[j] - S[i-1];
        if(sum == M)
            m1[i] = j;
        if(sum > M && sum <= minn){
            if(sum < minn){
                m2.clear();
                minn = sum;
            }
            m2[i] = j;
        }
    }
    
    if(m1.size() > 0)
        for(auto it = m1.begin(); it != m1.end(); it++)
            printf("%d-%d\n", it->first, it->second);
    else
        for(auto it = m2.begin(); it != m2.end(); it++)
            printf("%d-%d\n", it->first, it->second);
    
    return 0;
}
*/

//滑动窗口法，双指针
#include <cstdio>
#include <vector>
#include <map>
#include <climits>
using namespace std;

int main(void){
    int N, M;
    scanf("%d %d", &N, &M);
    
    vector<int> S(N+10);
    S[0] = 0;
    for(int i = 1; i <= N; i++){
        scanf("%d", &S[i]);
        S[i] += S[i-1];
    }
    
    map<int, int> m1, m2;
    int i = 1, j = 1, minn = INT_MAX;
    while(j <= N){
        int sum = S[j] - S[i-1];
        if(sum < M)
            j++;
        else if(sum == M){
            m1[i] = j;
            i++;
            j++;
        }
        else{
            if(sum <= minn){
                if(sum < minn){
                    m2.clear();
                    minn = sum;
                }
                m2[i] = j;
            }
            i++;
        }
    }
    
    if(m1.size() > 0)
        for(auto it = m1.begin(); it != m1.end(); it++)
            printf("%d-%d\n", it->first, it->second);
    else
        for(auto it = m2.begin(); it != m2.end(); it++)
            printf("%d-%d\n", it->first, it->second);
    
    return 0;
}
