#include <iostream>
#include <vector>

struct TNODE {
    int key;
    TNODE* pLeft;
    TNODE* pRight;
};

typedef TNODE* TREE;

struct Stack {
    std::vector<TNODE*> elements;

    void Push(TNODE* node) {
        elements.push_back(node);
    }

    TNODE* Pop() {
        if (IsEmpty())
            return NULL;
        TNODE* node = elements.back();
        elements.pop_back();
        return node;
    }

    TNODE* Top() {
        if (IsEmpty())
            return NULL;
        return elements.back();
    }

    bool IsEmpty() {
        return elements.empty();
    }
};

void CreateEmptyTree(TREE& t) {
    t = NULL;
}

TNODE* CreateTNode(int x) {
    TNODE* p = new TNODE;
    if (p == NULL)
        exit(1);

    p->key = x;
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}

int Insert(TREE& T, int x) {
    if (T) {
        if (T->key == x)
            return 0;
        if (T->key > x)
            return Insert(T->pLeft, x);
        return Insert(T->pRight, x);
    }
    T = CreateTNode(x);
    return 1;
}

void CreateTree(TREE& t) {
    t = NULL;
    int x;
    while (true) {
        cin >> x;
        if (x == -1)
            break;
        Insert(t, x);
    }
}

bool isLeafNode(TNODE* t) {
    return (t->pLeft == NULL && t->pRight == NULL);
}

bool SearchNode(TREE t, int x) {
    if (t == NULL)
        return false;
    if (t->key == x)
        return true;
    if (t->key > x)
        return SearchNode(t->pLeft, x);
    else
        return SearchNode(t->pRight, x);
}

void PrintDescendant(TNODE* t, int x, std::vector<int>& result) {
    if (t == NULL)
        return;
    if (t->key == x) {
        Stack stack;
        if (t->pLeft != NULL) {
            result.push_back(t->pLeft->key);
            stack.Push(t->pLeft);
        }
        if (t->pRight != NULL) {
            result.push_back(t->pRight->key);
            stack.Push(t->pRight);
        }

        while (!stack.IsEmpty()) {
            TNODE* node = stack.Pop();
            if (node->pLeft != NULL) {
                result.push_back(node->pLeft->key);
                stack.Push(node->pLeft);
            }
            if (node->pRight != NULL) {
                result.push_back(node->pRight->key);
                stack.Push(node->pRight);
            }
        }
    } else if (t->key > x)
        PrintDescendant(t->pLeft, x, result);
    else
        PrintDescendant(t->pRight, x, result);
}

void Function(TNODE* root) {
    TNODE* p = root;
    if (root == NULL) {
        cout << "Empty Tree.";
        return;
    }
    int k;
    cin >> k;

    std::vector<int> result;
    PrintDescendant(p, k, result);

    if (result.empty()) {
        cout << "No Descendants.";
    } else {
        cout << "Descendants: ";
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << " ";
        }
    }
}

int main() {
    TREE T;
    CreateTree(T);
    Function(T);
    return 0;
}
