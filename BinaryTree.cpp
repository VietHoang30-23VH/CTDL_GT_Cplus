#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *left,*right;
};
// Create empty binarytree
void CreateTree(node *&root)
{
    root=NULL;
}
// Create node in binarytree
node *CreateTreeNode ( int x )
{
    node *p=new node;
    p->data=x;
    p->left=NULL;
    p->right=NULL;
    return p;
}
// Insert a new into binarytree
node *insert( node *root, int x)
{
    if (root==NULL) root=CreateTreeNode(x);
    else 
    {   
        if (x>root->data)  root->right=insert(root->right,x);
        else root->left=insert(root->left,x);
    }
}
// Browsing binarytree
// Left-Node-Right
void InorderTraversal(node *root)
{
    if (root!=NULL)
    {
        InorderTraversal(root->left);
        cout<<root->data<< " " ;
        InorderTraversal(root->right);
    }
}
// Node-Left-Right
void PreorderTraversal(node *root)
{
    if (root!=NULL)
    {
        cout<<root->data<< " " ;
        PreorderTraversal(root->left);
        PreorderTraversal(root->right);
    }
}
// Left-Right-Node
void PosorderTraversal(node *root)
{
    if (root!=NULL)
    {
        PosorderTraversal(root->left);
        PosorderTraversal(root->right);
        cout<<root->data<< " " ;
    }
}
// Count Leaf Node 
bool isLeafNode(node *t)
{
    return (t->left==NULL && t->right==NULL);
}
int CountLeafNode(node *t)
{
    if (t==NULL) return 0;
    if (isLeafNode(t)!=0) return 1;
    else return CountLeafNode(t->left) + CountLeafNode(t->right);
}
// Print leaf node
void PrintLeaftNode (node *t)
{
    if (t!=NULL) 
    {   
        if (isLeafNode(t)!=0) cout<<t->data<< " ";
        PrintLeaftNode(t->left);
        PrintLeaftNode(t->right);
    } 
}
// Print level of binary tree
int treeLevel(node *t)
{
    if (t==NULL) return -1;
    if (isLeafNode(t)!=0) return 0;
    else return (1+max(treeLevel(t->left),treeLevel(t->right)));
}
// Check AVL tree 
bool CheckAVL (node *t)
{
    if (t==NULL) return true;
    if ( abs(treeLevel(t->left) - treeLevel(t->right)) > 1) return false;
    else return CheckAVL(t->left) && CheckAVL(t->right);
}
node *turnRight(node *t)
{
    node *b=t->left;
    node *c=b->right;
    t->left=c;
    b->right=t;
    return b;
}
node *turnLeft(node *t)
{
    node *b=t->right;
    node *d=b->left;
    t->right=d;
    b->left=t;
    return b;
}
void PrintTreeAVL(node *t)
{
    if (t!=NULL)
    // Print according to Inorder traversal
    {
        PrintTreeAVL(t->left);
        cout<<t->data<< " " ;
        if (t->left!=NULL) cout<<t->left->data<< " ";
        if (t->right!=NULL) cout<<t->right->data<< " ";
        PrintTreeAVL(t->right);
    }
}
node *UpdateAVLtree(node *t)
{
    if (abs (treeLevel(t->left)-treeLevel(t->right)) >1)
    {
        if (treeLevel(t->left)>treeLevel(t->right))
        {
            node *p=t->left;
            if (treeLevel(p->left)>=treeLevel(p->right))
            {
                t=turnRight(t);
            }
            else 
            {
                t->left=turnLeft(t->left);
                t=turnRight(t);
            }
        }
        else 
        {
            node *p=t->right;
            if (treeLevel(p->left)>=treeLevel(p->right))
            {   
                t->right=turnRight(t->right);
                t=turnLeft(t);
            }
            else 
            {
                t=turnLeft(t);
            }
        }
    }
    if (t->left!=NULL) t->left=UpdateAVLtree(t->left);
    if (t->right!=NULL) t->right=UpdateAVLtree(t->right);
    return t;
}
int countX(node *t,int x)
{
    if (t==NULL) return 0;
    if (t->data==x) return 1 + (countX(t->right,x) + countX(t->left,x));
    if (t->data<x) return countX(t->right,x);
    else return countX(t->left,x);
}
void deleteNode(node *t)
{
    if (t!=NULL)
    {
        if (t->left!=NULL) deleteNode(t->left);
        if (t->right!=NULL) deleteNode(t->right);
        delete(t);
    }
}
node *deleteNumber(node *t, int x)
{
    if (t!=NULL)
    {
        if (t->data==x)
        {
            deleteNode(t->left);
            deleteNode(t->right);
            t=NULL;
        }
        else if (t->data > x) t->left=deleteNumber(t->left,x);
        else t->right=deleteNumber(t->right,x);
    }
    return t;
}
// Find the Height of tree
int Height(node *t)
{
    if (t==NULL) return -1;
    int a=Height(t->right),b=Height(t->left);
    return 1 + max(a,b);
}
// Couting the number of node in tree
int CountingNode(node *t)
{
    if (t==NULL) return 0;
    int a=CountingNode(t->left),b=CountingNode(t->right);
    return 1+a+b;
}
// Finding max nodev
node *FindingMax(node *&t)
{
    if (t==NULL) return NULL;
    while (t->right!=NULL) 
    {
        t=t->right;
    }
    return t;
}
node *FindingMin(node *&t)
{
    if (t==NULL) return NULL;
    while (t->left!=NULL) 
    {
        t=t->left;
    }
    return t;
}
// MENUUUUUUU
// int main() {
//     node *t=NULL;
//     int choice, n, x, aco, k;
    
//     do {
//         cout << "MENU\n";
//         cout << "1. Insert value to tree\n";
//         cout << "2. Browse tree\n";
//         cout << "3. Count leaf nodes\n";
//         cout << "4. Print leaf nodes\n";
//         cout << "5. Print tree level\n";
//         cout << "6. Check AVL tree\n";
//         cout << "7. Transform to AVL tree\n";
//         cout << "8. Count nodes with value X\n";
//         cout << "9. Remove a value from tree\n";
//         cout << "0. Exit\n";
//         cout << "Enter your choice: ";
//         cin >> choice;
//         switch (choice) {
//             case 1:
//                 cout << "Enter the number of values to insert: ";
//                 cin >> n;
//                 for (int i = 0; i < n; i++) {
                    
//                     cin >> x;
//                     t = insert(t, x);
//                 }
//                 break;
//             case 2:
//                 cout << "Inorder Traversal: ";
//                 InorderTraversal(t);
//                 cout << endl;
//                 cout << "Preorder Traversal: ";
//                 PreorderTraversal(t);
//                 cout << endl;
//                 cout << "Postorder Traversal: ";
//                 PosorderTraversal(t);
//                 cout << endl;
//                 break;
//             case 3:
//                 cout << "Number of leaf nodes: " << CountLeafNode(t) << endl;
//                 break;
//             case 4:
//                 cout << "Leaf nodes: ";
//                 PrintLeaftNode(t);
//                 cout << endl;
//                 break;
//             case 5:
//                 cout << "Tree level: " << treeLevel(t) << endl;
//                 break;
//             case 6:
//                 if (CheckAVL(t))
//                     cout << "The tree is an AVL tree\n";
//                 else
//                     cout << "The tree is not an AVL tree\n";
//                 break;
//             case 7:
//                 cout << "Transforming to AVL tree...\n";
//                 while (!CheckAVL(t)) {
//                     t = UpdateAVLtree(t);
//                 }
//                 cout << "AVL tree:\n";
//                 PrintTreeAVL(t);
//                 break;
//             case 8:
//                 cout << "Enter the value to count: ";
//                 cin >> aco;
//                 cout << "Number of nodes with value " << aco << ": " << countX(t, aco) << endl;
//                 break;
//             case 9:
//                 cout << "Enter the value to remove: ";
//                 cin >> k;
//                 t = deleteNumber(t, k);
//                 if (t == NULL)
//                     cout << "The tree is empty\n";
//                 else {
//                     cout << "Inorder Traversal: ";
//                     InorderTraversal(t);
//                     cout << endl;
//                 }
//                 break;
//             case 0:
//                 cout << "Exiting...\n";
//                 break;
//             default:
//                 cout << "Invalid choice. Please try again.\n";
//                 break;
//         }
//     } while (choice != 0);
//     return 0;
// }
int main()
{
    node *t=NULL;
    int n,x;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>x;
        t=insert(t,x);
    }
    cout<<"...BROWSING..."<<endl;

    cout<<"\nSorting according to Inorder Traversal is: ";
    InorderTraversal(t);
    cout<<endl;
    cout<<"\nSorting according to Preorder Traversal is: ";
    PreorderTraversal(t);
    cout<<endl;
    cout<<"\nSorting according to Posorder Traversal is: ";
    PosorderTraversal(t);

    cout<<endl;
    cout<<"...Counting leaf node... "<<endl;
    cout<<CountLeafNode(t)<<endl;
    PrintLeaftNode(t);
    
    cout<<endl;
    cout<<"...Printing tree level..."<<endl;
    cout<<treeLevel(t);

    cout<<endl;
    cout<<"...Checking AVL..."<<endl;
    if (CheckAVL(t)==true) cout<< "true";
    else cout<<" false";

    cout<<endl;
    cout<<"...Transforming to AVL tree..."<<endl;
    while(!CheckAVL(t)) 
    {
        t=UpdateAVLtree(t);
       
    } 
    PrintTreeAVL(t);
    cout<<treeLevel(t);
    cout<<endl;
    int aco;
    cout<<"\n...Type the X requiring to count"<<endl;
    cin>>aco;
    cout<<"\n...Finding the number of value were same with x:";
    cout<<countX(t,aco);

    cout<<endl;
    int k;
    cout<<"\nType the number need to remove: "<<endl;
    cin>>k;
    t=deleteNumber(t,k);
    if (t==NULL) cout<<"NULL";
    else InorderTraversal(t);
    
    cout<<endl;
    cout<<"...Height of tree..."<<Height(t)<<endl;
    cout<<"...The number of node in tree..."<<CountingNode(t)<<endl;

    
    cout<<"...Finding Max node..."<<FindingMax(t)<<endl;
    cout<<"...Finding Min node..."<<FindingMin(t)<<endl;
    return 0;
}       
// #include <iostream>
// using namespace std;
// struct NODE
// {
//     int data;
//     NODE *l; NODE *r;
// };
// NODE *insertion(NODE *t,int x)
// {
//     if (t==NULL) 
//     {
//         NODE *temp=new NODE;
//         temp->data=x;
//         temp->l=NULL;
//         temp->r=NULL;
//         return temp;
//     }
//     else 
//     {
//         if (x<t->data)
//         {
//             t->l= insertion(t->l,x);
//         }
//         else 
//         {
//             t->r=insertion(t->r,x);
//         }
//     }
// }
// void printTree (NODE *t)
// {
//     if (t!=NULL) {printTree(t->l);
//     cout<<t->data<< " " ;
//     printTree(t->r);}
// }
// int main()
// {
//     int n,x;
//     cin>>n;
//     NODE *t=NULL;
//     for (int i=0;i<n;i++)
//     {
//         cin>>x;
//         t=insertion(t,x);
//     }
//     printTree(t);
// }



bool SearchNode(TREE t, int x) {
    if (t == NULL)
        return false;
    if (t->key == x) 
        return true;
    if (t->key > x)
        return SearchNode(t->pLeft, x);
    return SearchNode(t->pRight, x);
}

void PrintDescendant(TNODE *t) {
    if (t == NULL)
        return;
    if (t->pLeft != NULL) {
        cout << t->pLeft->key << " ";
        PrintDescendant(t->pLeft->pLeft);
        PrintDescendant(t->pLeft->pRight);
    }
    if (t->pRight != NULL) {
        cout << t->pRight->key << " ";
        PrintDescendant(t->pRight->pLeft);
        PrintDescendant(t->pRight->pRight);
    }
}

void Function(TREE t) {   
    int h;
    cin >> h;
    if (!SearchNode(t, h)) {
        cout << "No Find";
        return;
    } else if (isLeafNode(t)) {
        cout << "No descendant";
        return;
    } else {
        PrintDescendant(t);
    }
}