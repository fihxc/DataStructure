#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 0x7f7f7f7f;
const int N = 1e3 + 10;

struct Node
{
    int data, bf;
    Node *left, *right;
    Node() {}
    Node (int data, int bf, Node *left, Node *right):
        data(data), bf(bf), left(left), right(right) {}
} *T;

void init()
{
    T = NULL:
}

void left_balance(Node *T)
{
    Node *lc = T->left;
    switch (lc->bf)
    {
        case -1:
        case 0:
        case 1:
    }
}

bool insert(Node *T, int e, bool &taller)
{
    if (T == NULL)
    {
        T = new Node(e, 0, NULL, NULL);
        return taller = true;
    }
    if (e == T->data) 
    {
        return taller = false;
    }
    if (e < T->data)
    {
        if (!insert(T->left, e, taller)) return false;
        if (!taller) return true;
        switch (T->bf)
        {
            case -1:
                (T-bf)++;
                taller = false;
                break;
            case 0:
                T->bf = 1;
                taller = true;
                break;
            case 1:
                left_balance(T);
                taller = false;
                break;
        }
        return true;
    }
    if (e > T->data)
    {
        if (!insert(T->right, e, taller)) return false;
        if (!taller) return true;
        switch (T->bf)
        {
            case -1:
                right_balance(T);
                taller = false;
                break;
            case 0:
                T->bf = 1;
                taller = true;
                break;
            case 1:
                (T-bf)++;
                taller = false;
                break;
        }
        return true;
    }
}

void pre_order(Node *p)
{
    if (p == NULL) return;
    printf("%d ", p->data);
    pre_order(p->left);
    pre_order(p->right);
}


int main()
{
    int n;
    scanf("%d", &n);
    init();
    while (n--)
    {
        int a;
        scanf("%d", &a);
        bool taller;
        insert(T, a, taller);
    }

    pre_order(T);
    return 0;
}
