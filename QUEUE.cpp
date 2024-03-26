#include <bits/stdc++.h>
#define MAX 100
using namespace std;
typedef struct tagQueue 
{
    int a[MAX];
    int Front,Rear;
} Queue;
void CreateQueue(Queue &q)
{
    q.Front=-1;
    q.Rear=-1;
}
bool isEmpty(Queue q)
{
    if (q.Front==-1) return 1;
    return 0;
}
bool isFull(Queue q)
{
    if (q.Rear-q.Front +1 == MAX) return 1;
    return 0;
}
void EnQueue(Queue &q, int x) 
{
        int f, r;
        if (isFull(q)) //queue bị đầy => không thêm được nữa
        printf("queue day roi khong the them vao duoc nua");
        else {
        if (q.Front == -1) {
        q.Front = 0;
        q.Rear = -1;
        }
        if (q.Rear == MAX - 1) { //Queue đầy ảo
        f = q.Front;
        r = q.Rear;
        for (int i = f; i <= r; i++)
        q.a[i - f] = q.a[i];
        q.Front = 0;
        q.Rear = r - f;
        }
        q.Rear++;
        q.a[q.Rear] = x;
}
}