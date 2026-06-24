#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long LL;

#define MAXN 100100

struct edge
{
    int v;
    int next;
} e[MAXN*2];

struct tnode
{
    LL total, totalv;
} node[MAXN], x[MAXN];

int n, fr, s;
int p[MAXN];
int start[MAXN];
int sz[MAXN];
int q[MAXN];
int b[MAXN];

void add(int x, int y)
{
    fr++;
    sz[x]++;
    e[fr].v = y;
    e[fr].next = start[x];
    start[x] = fr;
}

bool xless( const tnode &a, const tnode &b)
{
    return (a.total > b.total) || (a.total == b.total && a.totalv > b.totalv);
}

int main()
{
    int X, Y;
    memset(start, 0, sizeof(start));
    memset(sz, 0, sizeof(sz));
    fr = 0;
    //freopen("e.in", "r", stdin);
    //freopen("e.out", "w", stdout);
    scanf("%i", &n);
    for(int i=1; i<=n; ++i) scanf("%i", &b[i]);
    for(int i=1; i<n; ++i)
    {
        scanf("%i %i", &X, &Y);
        add(X, Y);
        add(Y, X);
    }
    scanf("%i", &s);
    q[0] = s;
    p[s] = 0;
    int tail = 0;
    int head = 0;
    while (tail <= head)
    {
        int v = q[tail];
        int i = start[v];
        while (i != 0)
        {
            if (e[i].v != p[v])
            {
                head++;
                q[head] = e[i].v;
                p[e[i].v] = v;
            }
            i = e[i].next;
        }
        tail++;
    }

    b[s]++;
    sz[s]++;
    for(int w=head; w>=0; --w)
    {
        int v = q[w];
        if (b[v] == 0)
        {
            node[v].total =  0;
            node[v].totalv = 0;
        }
        else
            if (sz[v] == 1) // leaf
            {
                node[v].total = 1;
                node[v].totalv = b[v] - 1;
            }
            else                
            {
                int i = start[v];
                int k = 0;
                while (i != 0)
                {
                    int j = e[i].v;
                    if (j != p[v] && node[j].total > 0)
                    {
                        x[k++] = node[j];
                    }
                    i = e[i].next;
                }
                if (k==0)
                {
                    node[v].total = 1;
                    node[v].totalv = b[v] - 1;
                }
                else
                {
                    sort(&x[0], &x[k], xless);
                    b[v]--;
                    if (b[v] < k)
                    {
                        node[v].totalv = 0;
                        node[v].total = 1 + b[v];
                        for(i=0; i<b[v]; ++i) node[v].total += x[i].total;
                    }
                    else
                    {
                        node[v].total = 1 + k;
                        for(i=0; i<k; ++i) node[v].total += x[i].total;
                        b[v] -= k;
                        for(i=0; i<k && b[v]; ++i)
                        {
                            if (b[v] > x[i].totalv)
                            {
                                b[v] -= x[i].totalv;
                                node[v].total += x[i].totalv*2;
                            }
                            else
                            {
                                node[v].total += b[v]*2;
                                b[v] = 0;
                            }
                        }
                        node[v].totalv = b[v];
                    }
                }
            }
    }
    printf("%I64d\n", node[s].total - 1);
    return 0;
}