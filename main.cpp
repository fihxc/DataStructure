/*
20.平衡二叉树
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 0x7f7f7f7f;
const int N = 1e3 + 10;

struct Node
{
    char data;
    int bf;
    Node *left, *right;
    Node() {}
    Node (int data, int bf, Node *left, Node *right):
        data(data), bf(bf), left(left), right(right) {}
} *T;

void init()
{
    T = NULL:
}

void insert(Node *T, char c)
{
    
}

void pre_order(Node *T)
{
    if (T == NULL) return;
    printf("%c", T->data);
    pre_order(T->left);
    pre_order(T->right);
}

void in_order(Node *T)
{
    if (T == NULL) return;
    in_order(T->left);
    printf("%c", T->data);
    in_order(T->right);
}

void post_order(Node *T)
{
    if (T == NULL) return;
    post_order(T->left);
    post_order(T->right);
    printf("%c", T->data);
}

void in_order_indent(Node *T, int deep)
{
    if (T == NULL) return;
    for (int i = 1; i <= deep; i++) printf("    ");
    indent(T->left, deep + 1);
    printf("%c\n", T->data);
    indent(T->right, deep + 1);
}

int main()
{
    init();
    char c;
    while ((c = getchar()) != '\n') insert(T, c);

    printf("Preorder: ")
    pre_order(T);
    printf("\n");

    printf("Inorder: ");
    in_order(T);
    printf("\n");

    printf("Postorder: ");
    post_order(T);
    printf("\n");

    printf("Tree:\n");
    in_order_indent(T, 0);
    return 0;
}
