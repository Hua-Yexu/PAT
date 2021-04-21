#include <cstdio>

int main(void){
    int K, data[100001], start = -1, end, sum = -1;
    
    scanf("%d", &K);
    for(int i = 0; i < K; i++)
        scanf("%d", &data[i]);
    
    for(int i = 0, temp = 0, j = 0; i < K; i++){
        temp += data[i];
        if(temp < 0)
            temp = 0, j = i + 1;
        else if(temp > sum)
            sum = temp, start = j, end = i;
    }
    
    if(start == -1)
        printf("0 %d %d", data[0], data[K-1]);
    else
        printf("%d %d %d", sum, data[start], data[end]);
    
    return 0;
}
