
#include <iostream> 
using namespace std;

struct TNODE {
	int key;
	TNODE* pLeft;
	TNODE* pRight;
};

typedef TNODE* TREE; 
void CreateEmptyTree(TREE &t)
{
    t=NULL;
}
TNODE* CreateTNode(int x) {
    TNODE *p = new TNODE; 
    if (p == NULL)

    exit(1);

    p->key = x;
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}
int Insert(TREE &T, int x) 
{
    if (T) 
    {
    if (T->key == x) return 0;
    if (T->key > x)

    return Insert(T->pLeft, x);

    return Insert(T->pRight, x);
    }
    T = CreateTNode(x);
    return 1;
}
void CreateTree(TREE &t)
{
    t=NULL;
    int x;
    while(true)
    {
        cin>>x;
        if (x==-1) break;
        Insert(t,x);
    }  
}
bool isLeafNode(TNODE *t)
{
    return (t->pLeft==NULL && t->pRight==NULL);
}
bool SearchNode(TREE t,int x)
{   
    if (t==NULL) return false;
    if (t->key==x) return true;
    if (t->key >x) return SearchNode(t->pLeft,x);
    else return SearchNode(t->pRight,x);
}

void PrintDescendant(TNODE *t, int x)
{
    if (t==NULL) return;
    if (t->key==x)
    {
        stack stack 
        if (t->pLeft!=NULL)
        {   
            result.push_bak(T->left->key);
            stack.Push(t->left);
            cout<<t->pLeft->key<< " ";
            PrintDescendant(t->pLeft,x);
        }
        if (t->pRight!=NULL)
        {
            cout<<t->pRight->key<< " ";
            PrintDescendant(t->pRight,x);
        }
    }
    else if (t->key >x ) PrintDescendant(t->pLeft,x);
    else PrintDescendant(t->pRight,x);
}
void Function(TNODE *root)
{
    TNODE *p = root;
    if (root == NULL)
    {
        cout << "Empty Tree.";
        return;
    }
    int k;
    cin >> k;
    printDesCendant(p, k);
}

int main() {
	TREE T;  
	CreateTree(T); 
	Function(T);
	return 0;
}
