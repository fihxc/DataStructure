#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 0x7f7f7f7f;
const int N = 1e3 + 10;

struct Node
{
    int data;
    Node *left, *right;
    Node(): left(NULL), right(NULL) {}
    Node(int data, Node *left, Node *right): 
        data(data), left(left), right(right) {}
};
Node *H;

void init()
{
    H = new data;
}

void insert(char s[])
{
    int len = strlen(s);
    Node *p = H;
    bool flag = false;
    for (int i = 0; i < len; i++)
    {
        if (s[i] == 0)
        {
            if (p->left)
        }
        else
        {

        }
    }
}

char s[N];
int main()
{
    init();
    int n;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%s", s);
        if (!insert(s))
        {
            printf("%s\n", s);
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}
