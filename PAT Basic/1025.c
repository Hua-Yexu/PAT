//坑：可能有链表外的点

//法一：
#include <stdio.h>

typedef struct
{
    int data;
    int next;
}node;

void reverse(int sequ[], int a, int K)
{
    int temp;
    for(int left = a-K+1, right = a; left < right; left++, right--)
    {
        temp = sequ[left];
        sequ[left] = sequ[right];
        sequ[right] = temp;
    }
}

int main(void)
{
    node list[100001];
    int N, K, first, add, cnt = 0;
    int sequ[100001];

    scanf("%d %d %d",&first, &N, &K);
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &add);
        scanf("%d %d", &list[add].data, &list[add].next);
    }

    for(int p = first; p != -1; p = list[p].next)
        sequ[cnt++] = p;

    for(int i = 1; i*K <= cnt; i++)
        reverse(sequ, i*K-1, K);

    for(int i = 0; i < cnt-1; i++)
        printf("%05d %d %05d\n", sequ[i], list[sequ[i]].data, sequ[i+1]);
    printf("%05d %d -1\n", sequ[cnt-1], list[sequ[cnt-1]].data);

    return 0;
}


//法二：
#include <stdio.h>

typedef struct
{
    int add;
    int data;
    int next;
}node;

void reverse(node list[], int a, int K)
{
    node temp;
    for(int left = a-K+1, right = a; left < right; left++, right--)
    {
        temp = list[left];
        list[left] = list[right];
        list[right] = temp;
    }      
}

int main(void)
{
    node list[100001];
    node temp;
    int N, K, first, cnt = 0;
    
    scanf("%d %d %d",&first, &N, &K);
    for(int i = 0; i < N; i++)
        scanf("%d %d %d", &list[i].add, &list[i].data, &list[i].next);
    
    for(int i = 0; first != -1; i++)
    {
        for(int j = i; j < N; j++)
            if(first == list[j].add)
            {
                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
                break;
            }
        first = list[i].next;
        cnt++;
    }
    
    for(int i = 1; i*K <= cnt; i++)
        reverse(list, i*K-1, K);
    
    int i;
    for(i = 0; i < cnt-1; i++)
        printf("%05d %d %05d\n", list[i].add, list[i].data, list[i+1].add);
    printf("%05d %d -1\n", list[i].add, list[i].data);
    
    return 0;
}
