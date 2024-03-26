#include <bits/stdc++.h>
using namespace std;

struct node
{
    int key;
    node* left;
    node* right;
};

typedef node* tree;

void CreateEmptytree(tree& T)
{
    T = NULL;
}

node* CreatetreeNode(int x)
{
    node* p = new node;
    if (p == NULL) exit(1);
    p->key = x;
    p->left = p->right = NULL;
    return p;
}

bool InsertNode(tree& T, int x)
{
    if (T != NULL)
    {
        if (T->key == x) return false;
        else if (T->key > x) InsertNode(T->left, x);
        else InsertNode(T->right, x);
    }
    else
    {
        T = CreatetreeNode(x);
        return true;
    }
}

void Createtree(tree& t)
{
  int n;
  cin>>n;
  for (int i=0;i<n;i++)
  {
    int x;cin>>x;
    InsertNode(t,x);
  }
}

void Preorder(tree t)
{
    if (t != NULL)
    {
        if (t->left != NULL && t->right != NULL)
            cout << t->key << " ";
        Preorder(t->left);
        Preorder(t->right);
    }
}

void Inorder(tree t)
{
    if (t != NULL)
    {
        Inorder(t->left);
        cout << t->key << "\t";
        Inorder(t->right);
    }
}

void Postorder(tree t)
{
    if (t != NULL)
    {    
        Postorder(t->left); 
        Postorder(t->right); 
        cout << t->key << " ";
    }
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
void PrintNodeOneChild(tree &t)
{
    if (t!=NULL)
    {
        if ( (t->left!=NULL && t->right==NULL) || (t->left==NULL && t->right!=NULL))
        {
            cout<<t->key<<" ";
        }
    }
    PrintNodeOneChild(t->left);
    PrintNodeOneChild(t->right);
}
void PrintNodesWithOneChild(tree &t)
{
    if (t == NULL)
        return;
     bool hasOneChild = (t->left == NULL && t->right != NULL) || (t->left != NULL && t->right == NULL);
    if (hasOneChild)
        cout << t->key << " ";

    PrintNodesWithOneChild(t->left);
    PrintNodesWithOneChild(t->right);
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
void PrintNodeLevelK(tree&t, int level)
{
    if (t!=NULL)
    {
        if (level == 1)
        {
            cout << t->key << " ";
        }
        else if (level > 1)
        {
            PrintNodeLevelK(t->left, level - 1);
            PrintNodeLevelK(t->right, level - 1);
        }   
    }
}
// Tìm Min-Max
node* FindMin(tree &t)
{
    if (t==NULL ) return NULL;
    if (t->left==NULL) return t;
    return FindMin(t->left);
}
node* FindMax(tree &t)
{       
    if (t->right==NULL) return t;
    return FindMax(t->right);
}
// Xóa node có trường key=x
void ThayThe(tree &p, tree &t)
{
    if (t->left!=NULL) ThayThe(p,t->left);
    else {
        p->key=t->key;
        p=t;
        t=t->right;
    }
}
void DeleteNode ( tree &t, int x)
{
    if (t!=NULL)
    {
        if (t->key < x ) DeleteNode(t->right,x);
        else 
        {
            if (t->key > x) DeleteNode (t->left,x);
            else 
            {
                TNode *p;
                p=t;
                if (t->left == NULL ) t=t->right;
                else 
                {
                    if (t->right==NULL ) t=t->left;
                    else ThayThe(p,t->right);
                }
                delete p;
            }
        }
    }
}
// Tìm chiều cao của NODE 
int HeightOftree(TNode * t)
{
    if (!t) return -1;
    int a=HeightOftree(t->left),b=HeightOftree(t->right);
    return (a>b ? a:b)+1;
}
// Đếm số lượng NODE có trong cây
int NodeCounting(tree t)
{
    if (t==NULL) return 0;
    int a=NodeCounting(t->left),b=NodeCounting(t->right);
    return (a+b+1);
}
void PrintNodeK(tree &t)
{
    int k;
    cin>>k;
    PrintNodeLevelK(t, k);
    cout << endl;
}
int main()
{
    tree t;
    CreateEmptytree(t);
    Createtree(t);
    while(true)
    {
        int loai;
        cin>>loai;
        cout<<"=== DANH SACH THAO TAC ==="<<endl;
        cout<<"1. Node - Left - Right"<<endl;
        cout<<"2. Left - Node - Right"<<endl;
        cout<<"3. Left - Right - Node"<<endl;
        cout<<"4. Tong so node co 1 con"<<endl;
        cout<<"5. In ra node co 1 con"<<endl;
        cout<<"6. Dem so node co 2 con"<<endl;
        cout<<"7. Xuat cac node o tang K"<<endl;
        cout<<"8. Find Min"<<endl;
        cout<<"9. Find Max"<<endl;
        cout<<"10. Xoa Node"<<endl;
        cout<<"11. Chieu cao cay"<<endl;
        cout<<"12. Dem so node"<<endl;
        switch (loai)
        {
        case 1:
        {
            
        }
            break;
        
        default:
            break;
        }
    }
    return 0;
}

