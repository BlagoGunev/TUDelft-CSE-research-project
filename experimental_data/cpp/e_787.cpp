#include <bits/stdc++.h>

using namespace std;

int tab[100010];
int out[100010];
int pos[100010];
const int pot = 131072;
int tree[2*pot+10];
int last[100010];
int nxt[100010];
vector<int> q[100010];

void tree_add(int v, int x)
{
    v += pot - 1;
    while (v >= 1)
    {
        tree[v] += x;
        v >>= 1;
    }
}

int tree_find(int v, int x)
{
    if (v >= pot) return v - pot;
    if (tree[v<<1] <= x) return tree_find((v<<1) + 1, x - tree[v<<1]);
    return tree_find((v<<1), x);
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &tab[i]);
        last[i] = n + 1;
        q[1].push_back(i);
    }
    for (int i = n; i >= 1; i--)
    {
        nxt[i] = last[tab[i]];
        last[tab[i]] = i;
    }

    tree_add(n + 1, 1000000);
    for (int i = 1; i <= n; i++) tree_add(last[i], 1);

    for (int i = 1; i <= n; i++)
    {
        while (!q[i].empty())
        {
            int x = q[i][q[i].size() - 1];
            q[i].pop_back();
            out[x]++;
            int id = tree_find(1, x);
            q[id + 1].push_back(x);
        }
        tree_add(i, -1);
        tree_add(nxt[i], 1);
    }

    for (int i = 1; i <= n; i++) printf("%d ", out[i]);
}