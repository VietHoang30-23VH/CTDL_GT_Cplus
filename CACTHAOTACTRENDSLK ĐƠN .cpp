#include <bits/stdc++.h>
using namespace std;
struct Node 
{
    int data;
    Node *next;
};
struct List 
{
    Node *pHead;
    Node *pTail;
};
void CreateEmptyList(List &L)
{
    L.pHead=L.pTail=NULL;
}
Node* CreateNode(int x)
{
    Node *p= new Node;
    p->data=x;
    p->next=NULL;
    return p;
}
void AddHead(List &L,int x)
{
    Node *p=CreateNode(x);
    if (L.pHead==NULL) 
    {
        L.pHead=p;
        L.pTail=L.pHead;
    }
    else 
    {
        p->next=L.pHead;
        L.pHead=p;
    }
}
void RemoveHead(List &L)
{
    if (L.pHead==NULL) return NULL;
    Node *p=L.pHead;
    L.pHead=L.pHead->next;
    delete p;
}
void AddTail(List &L,int x)
{
    Node *p=CreateNode(x);
    if (L.pHead==NULL)
    {
        L.pHead=p;
        L.pTail=L.pHead;
    }
    else 
    {
        L.pTail->next=p;
        L.pTail=p;
    }
}
void RemoveTail(List &L)
{
    if (L.pHead==NULL) return NULL;
    if (L.pHead->next==NULL) RemoveHead(L);
    for (Node*k=L.pHead;k!=NULL;k=k->next)
    {
        if (k->next==L.pTail)
        {
            delete L.pTail;
            k->next=NULL;
            L.pTail=k;
            return;
        }
    }
}
void AddNodeAfter_q(List &L, Node *p)
{
    int x;
    cin>>x;
    Node *q=CreateNode(x);
    if (q->data==L.pHead->data && L.pHead->next==NULL)
    {
        AddTail(L,x);
    }
    else 
    {
        for (Node *k=L.pHead;k!=NULL;k=k->next)
        {
            if (q->data==k->data)
            {
                Node *h=CreateNode(p->data);
                h->next=k->next;
                k->next=h;
            }
        }
    }
}
void RemoveAfter_q(List &L,Node *p)
{
    for (Node *k=L.pHead;k!=NULL;k=k->next)
    {
        if (k->data==p->data)
        {
            Node*g=k->next;
            k->next=g->next;
            delete g;
        }
    }
}
void RemoveX(List &L,int x)
{
    if (L.pHead->data==x) RemoveHead(L,x);
    if (L.pTail->data==x) RemoveTail(L,x);
    else 
    {
        Node *p=L.pHead;
        for (Node *k=L.pHead;k!=NULL;k=k->next)
        {
            if (k->data==x)
            {
                p->next=k->next;
                delete k;
            }
        }
        p=k;
    }
}
void RemoveList(List L)
{
    Node *p=L.pHead;
    while(p!=NULL)
    {
        L.pHead=p->next;
        delete p;
        p=L.pHead;
    }
}
void PrintList(List &L)
{
    Node *p;
    if (L.pHead==NULL) return nullptr;
    else 
    {
        p=L.pHead;
        while(p!=NULL )
        {
            cout<<p->data<<"\t";
            p=p->next;
        }
    }
    cout<<endl;
}
void AddNodeIntoParticularPos(List &L,Node *p, int vt)
{
    if (vt<=0) return nullptr;
    if (vt==1) 
    {
        AddTail(L,p);
    }
    Node *q=L.pHead;
    int dem=1;
    while(q!=NULL && dem <vt-1)
    {
        q=q->next;
        dem++;
    }
    if (q==NULL) return;
    p->next=q->nex;
    q->next=p;
    if (p->next==NULL) L.pTail=p;
}