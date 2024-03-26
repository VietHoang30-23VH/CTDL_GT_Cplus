#include <iostream>

using namespace std;

struct Node
{
    int info;
    Node* next;
};

struct List
{
    Node* head=NULL;
    Node* tail=NULL;
};

struct Graph
{
    int v; // số đỉnh của đồ thị 
    List* arr; //mảng của các danh sách
};
void KhoiTaoList(List &l)
{
    l.pHead = NULL;
    l.pTail = NULL;
}
Node *KhoiTaoNode (int x)
{
    Node *p = new Node;
    if( p==NULL)
    {
        cout<<"Khong du bo nho";
        return NULL;
    }
    p->data = x;
    p->pNext = NULL;
}
void Input(Graph&G,int x)
{
    
}
 
int main()
{
    int e,v;
    cin>>e>>v;
    Graph G;
    G.v=v;
    G.arr = new List[v];
    Input(G,e);

    return 0;
}