#include <stdio.h>
#define N 1000010

struct pair
{
    int r, s;
} a[N];
int top;

int find(struct pair a[], int top, int r, int s)
{
    for (int i = 0; i < top; i++)
        if (a[i].r == r && a[i].s == s) return i;
    return -1;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    int index;
    top = 0;
    n *= 10;
    int ss = n / m;
    while (n && (index = find(a, top, n, ss)) == -1)
    {
        a[top].r = n; a[top].s = ss; top++;
        n %= m;
        n *= 10;
        ss = n / m;
    }

    if (n == 0)
    {
        printf("ring=0\n");
        printf("NULL\n");
        return 0;
    }
    printf("ring=%d\n", top - index);
    for (int i = index; i < top; i++) printf("%d", a[i].s);
    printf("\n");
    return 0;
}
