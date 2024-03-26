#include <bits/stdc++.h>
using namespace std;

struct NguoiMuaVe
{
    string name;
    int soluongve;
    int loaighe;
    string ngaythangnam;
    int loaive;
};
struct node
{
    NguoiMuaVe info;
    node*next;
};
struct List
{
    node*head;
    node*tail;
};
void CreateEmptyList(List &l)
{
    l.head=l.tail=NULLp;
}
node * CreateNode(NguoiMuaVe x)
{
    node *p=new node;
    p->info=x;
    p->next=NULL;
    return p;
}
void NhapDanhSach(List &l, int n)
{
    for (int i=0;i<n;i++)
    {
        NguoiMuaVe nguoi;
        cin.ignore();
        getline(cin,nguoi.name);
        cin>>nguoi.soluongve;
        cin>>nguoi.loaighe;
        getline(cin,nguoi.ngaythangnam);
        cin>>nguoi.loaive;
        
    }
}
// THEM DAU, THEM CUOI
void AddTail(List &l,NguoiMuaVe x)
{
    node *p=new node;
    p->info=x;
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
void AddHead(List &l,NguoiMuaVe x)
{
    node *p=new node;
    p->info=x;
    p->next=nullptr;
    if (l.head==NULL)
    {
        l.head=p;
        l.tail=l.head;
    }
    else 
    {
        p->next=l.head;
        l.head=p;
    }
}
// XOA DAU, XOA CUOI 
void RemoveHead(List &l)
{
    if (l.head==NULL) return NULL;
    node *p=l.head;
    l.head=l.head->next;
    delete p;
}
void RemoveTail(List &l)
{
    if (l.head==NULL) return NULL;
    if (l.head->next==NULL)
    {
        RemoveHead(l);
        return;
    }
    for (node *k=l.head;k!=NULL;k=k->next)
    {
        if (k->next==l.tail)
        {
            delete l.tail;
            k->next=NULL;
            l.tail=k;
            return ;
        }

    }
}
void RemoveX(List&l,NguoiMuaVe x)
{
    if (l.head->info==x) RemoveHead(l);
    if (l.tail->info==x) RemoveTail(l);
    else
    {
        node *p=l.head;
        for (node *k=l.head;k!=NULL;k=k->next)
        {
            if (k->data==x)
            {
                g->next=k->next;
                delele k;
                return ;
            }
            g=k;
        }
    }
}
void XuatList(List &l)
{
    node * p;
    if (l.head==NULL) 
    {
        cout<<"Empty list.";
        return;
    }
    else 
    {
        p=l.head;
        while(p)
        {
            cout<<p->info.name<<endl;
            p=p->next;
        }
    }
    cout<<endl;
}