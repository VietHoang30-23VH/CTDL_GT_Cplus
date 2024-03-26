#include <bits/stdc++.h>
using namespace std;
struct TNode
{
    int key;
    TNode *pLeft,*pRight;
};
typedef TNode *Tree;
// Tìm node có giá trị là x không dùng đệ quy
TNode *SearchNode1 (Tree ROOT,int x)
{
    TNode *p=ROOT;
    while (p!=NULL)
    {
        if (x == p->key) return p;
        if (x < p->key) p=p->pLeft;
        else p=p->pRight;
    }
    return NULL;
}
// Tìm node có giá trị x dùng đệ quy
TNode *SearchNode2 (Tree t,int x)
{
    if (t!=NULL)
    {
        if (t->key == x) return t;
        if (t->key > x) return SearchNode2(t->pLeft,x);
        else return SearchNode2(t->pRight,x);
    }
    return NULL;
}
// Tạo Cây Rỗng
void CreateTree (Tree &t)
{
    t=NULL;
}
// Tạo 1 node có key bằng x vào cây
TNode *CreateTreeNode (int x)
{
    TNode *p=new TNode;// cap phat vung nho
    if (p==NULL) exit(1);
    p->key=x;
    p->pLeft=NULL;
    p->pRight=NULL;
    return p;
}
// Thêm giá trị x vào cây
bool insertion(Tree &ROOT,int x)
{
    if (ROOT==NULL) {ROOT=CreateTreeNode(x);
                    return true;}
    Tree t=ROOT;
    while (t!=0)
    {
        if (t->key == x ) return false;
        if (t-> key > x) 
        {
            if (t->pLeft == NULL )
            t->pLeft = CreateTreeNode(x);
            else t=t->pLeft;
        }
        else 
        {
            if (t->pRight == NULL )
            t->pRight= CreateTreeNode(x);
            else t=t->pRight;
        }
    }
    return true ;
}
// Duyệt cây nhị phân
 
// Duyệt trước 
void Preorder (Tree ROOT)
{
    if (ROOT!=NULL)
    {
        if (ROOT->pLeft!=NULL && ROOT->pRight!=NULL)
        cout<<ROOT->key<<" ";
        Preorder(ROOT->pLeft);
        Preorder(ROOT->pRight);
    }
}
// Duyệt giữa 
void Inorder(Tree ROOT)
{      
    
    if (ROOT!=NULL)
    {
        Inorder(ROOT->pLeft);
        cout<<ROOT->key<<"\t";
        Inorder(ROOT->pRight);
    }
}
// Duyệt sau
void Postorder(Tree ROOT)
{
    
    if(ROOT!=NULL)
    {
        Postorder(ROOT->pLeft);
        Postorder(ROOT->pRight);
        cout<<ROOT->key<<" ";
    }
}
// Tìm Min-Max
TNode* FindMin(Tree &t)
{
    if (t==NULL ) return NULL;
    if (t->pLeft==NULL) return t;
    return FindMin(t->pLeft);
}
TNode* FindMax(Tree &t)
{       
    if (t->pRight==NULL) return t;
    return FindMax(t->pRight);
}
// Xóa node có trường key=x
void ThayThe(Tree &p, Tree &t)
{
    if (t->pLeft!=NULL) ThayThe(p,t->pLeft);
    else {
        p->key=t->key;
        p=t;
        t=t->pRight;
    }
}
void DeleteNode ( Tree &t, int x)
{
    if (t!=NULL)
    {
        if (t->key < x ) DeleteNode(t->pRight,x);
        else 
        {
            if (t->key > x) DeleteNode (t->pLeft,x);
            else 
            {
                TNode *p;
                p=t;
                if (t->pLeft == NULL ) t=t->pRight;
                else 
                {
                    if (t->pRight==NULL ) t=t->pLeft;
                    else ThayThe(p,t->pRight);
                }
                delete p;
            }
        }
    }
}
// Tìm chiều cao của NODE 
int HeightOfTree(TNode * t)
{
    if (!t) return -1;
    int a=HeightOfTree(t->pLeft),b=HeightOfTree(t->pRight);
    return (a>b ? a:b)+1;
}
// Đếm số lượng NODE có trong cây
int NodeCounting(Tree t)
{
    if (t==NULL) return 0;
    int a=NodeCounting(t->pLeft),b=NodeCounting(t->pRight);
    return (a+b+1);
}
int sumOneChild(tree&t)
{
    if (t==NULL) return 0;
    int sum=0;
    if ((t->left==NULL && t->right!=NULL)||(t->left!=NULL && t->right==NULL))
    {
        sum+=t->key;
    }
    sum+=sumOneChild(t->left);
    sum+=sumOneChild(t->right);
    return sum;
}
int Count2Decensendant(tree &t)
{
    if (t==NULL) return 0;
    int count=0;
    if ( (t->left!=NULL && t->right!=NULL)) count++;
    count+=Count2Decensendant(t->left);
    count+=Count2Decensendant(t->right);
    return count;
}

// in ra cac node cung bac
void PrintLevelK(tree &t, int k)
{
    if(t!=NULL)
    {
        if (k==0) cout<<t->key<< " ";
        else if (k>0)
        {
            PrintLevelK(t->left,k-1);
            PrintLevelK(t->right,k-1);
        }
    }
}
// xuat con 
void PrintDescendant(tree &t, int x)
{
    if (t!=NULL)
    {
        if (t->key == x) 
        {
            if (t->left!=NULL)
            {
                 cout<<t->left->key<< " ";
                 PrintDescendant(t->left,x);
            }
            if (t->right!=NULL)
            {
                cout<<t->key->right<<" "; 
                PrintDescendant(t->right,x);
            }
        }
        else if (t->key >x) PrintDescendant(t->left,x);
        else return PrintDescendant(t->right,x);
    }
}
// Ham tim kiem
node * FindNode(tree &t,int x)
{
    if (t==NULL) return NULL;
    else 
    {
        if (t->key==x) return t;
        else if (t->key> x) return FindNode(t->left,x);
        else return FindNode(t->right,x);
    }
    return nullptr;
}
// XuatCha
void PrintAncestor(tree &t, tree& p)
{
    if (t==NULL || t==p ) return ;
    else 
    {
        if (t->key > p->key)
        {
            cout<<t->key<<" ";
            PrintAncestor(t->left,p);
        }
        else 
        {
            cout<<t->key<<" ";
            PrintAncestor(t->right,x);
        }
    }
}
void function(tree &t)
{   
    int x;
    cin>>x;
    
    PrintAncestor(t,FindNode(t,x));
}
// tim max trai 
void MaxLeft(tree &t, int x)
{
    int val=-1;
    while (t!=NULL)
    {
        if (t->key==x)
        {
            if (t->left!=NULL && t->right!=NULL)
            {
                t=t->left;
                val=t->key;
                break;
            }
            else 
            {
                cout<<"No node ";
                return;
            }
        }
        else if (t->key > x)
        {
            t=t->left;
        }
        else 
        {
            t=t->right;
        }
    }
    if (val==-1 ) cout<"Invalid value.";
    else 
    {
        while (t->right!=NULL)
        {
            t=t->right;
            val=t->key;
        }
        cout<<val<<endl;
    }
}
void MinPhai(tree&t,int x)
{
    int min_val=10000;
    while(t!=NULL)
    {
        if (t->key==x) 
        {
            if (t->left!=NULL && t->right!=NULL)
            {
                t=t->right;
                min_val=t->key;
                break;
            }
        }
            else if (t->key>x)
            {
                t=t->left;
            }
            else t=t->right;
        
    }
    if (min_val==10000) cout<<"Invalid.";
    else 
    {
        while(t->left!=NULL)
        {
            t=t->left;
            min_val=t->key;
        }
        cout<<min_val;
    }

}
int main()
{
    Tree t;
    CreateTree(t);
    HeightOfTree(t);
    FindMax(t);
    FindMin(t);
    return 0;
}
