#include <bits/stdc++.h>
using namespace std;
struct SIEUTHI
{
    int masieuthi;
    char tensieuthi[50];
    int namthanhlap;
    int soluongnhanvien;
};
struct node 
{
    SIEUTHI info;
    node *next;
};
struct LIST
{
    node *head;
    node* tail;
};
void CreateEmptyList(LIST &l)
{
    l.head=l.tail=NULL;
}
node*CreateNode(SIEUTHI x)
{
    node*p=new node;
    p->info=x;
    p->next=NULL:
    return p;
}
void AddHead(LIST &l,SIEUTHI st)
{
    node *p=new node;
    p->info=st;
    p->next=NULL:;
    if (l.head==NULL)
    {
        l.head=p;
        l.tail=l.head;
    }
    else 
    {
        l.head=p;
        p->next=l.head;
    }
}
void AddTail(LIST &l,SIEUTHI st)
{
    node *p=new node;
    p->info=st;
    p->next=nullptr;
    if (l.head==NULL)
    {
        l.head=p;
        l.tail=l.head;
    }
    else 
    {
        l.tail->next=p;
        l.tail=p;
    }
}
void RemoveHead(LIST &l){
    if (l==NULL) return;
    else 
    {
        node*p=l.head;
        l.head=l.head->next;
        delete p;
    }
}
void RemoveTail(LIST &l)
{
    if (l==NULL) return;
    if (l .head->next==NULL)
    {
        RemoveHead(l);
        return;
    }
    else 
    {
        for (node*k=l.head;k!=NULL;k=k->next)
        {
            if (k->next==l.tail)
            {
                delete l.tail;
                k->next=NULL:
                l.tail=k;
                return ;
            }
        }
    }
}
void NhapDanhSach(LIST &l,int n)
{
    for (int i=0;i<n;i++)
    {
        SIEUTHI x;
        cout<<"Ma sieu thi"<<endl;
        cin>>x.masieuthi;
        cin.ignore();
        cout<<"Ten sieu thi"<<endl;
        cin>>x.tensieuthi;
        cout<<"Nam thanh lap"<<endl;
        cin>>x.namthanhlap;
        cout<<"So luong nhan vien "<<endl;
        cin>>x.soluongnhanvien;
        AddTail(l,x);
    }
}
void XuatDanhSach(LIST &l)
{
    node*p;
    if (l.head==NULL) {cout<<"Empty List";return;}
    else 
    {
        p=l.head;
        for (node *k=l.head;k!=NULL;k=k->next)
        {
            if (p->info.namthanhlap>10)
            {
                cout<<p->info.masieuthi<<endl;
                cout<<p->info.namthanhlap<<endl;
                cout<<p->info.soluongnhanvien<<endl;
                cout<<p->info.tensieuthi<<endl;
             
            }
        }
    }
    cout<<endl;
}
void XoaSieuThi(LIST &l,SIEUTHI st)
{
    node *tmp=l.head;

    {
        for ( node *k=l.head->next;k!=NULL;k=k->next)
        {
            if (k->info.namthanhlap<100)
            {
                g->next=k->next;
                delete k;
                return ;
            }    
        }
        g=k;
    }
}
void XOALIST(LIST &l)
{
    node *p;
    while(l.head!=NULL)
    {
        l.head=p->next;
        delete p;
        p=l.head;
    }
}