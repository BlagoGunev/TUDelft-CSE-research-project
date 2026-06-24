/*
    Take me to church
    I'll worship like a dog at the shrine of your lies
    I'll tell you my sins and you can sharpen your knife
    Offer me that deathless death
    Good God, let me give you my life
*/
#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int N = 1000006;
int n, m, P[N], W[N], V[N], U[N], S[N];
vector < pair < int , int > > vec[N];
bool MST[N];
int Find(int v)
{
    return (P[v] < 0 ? v : (P[v] = Find(P[v])));
}
inline bool CMP(int i, int j)
{
    return (W[i] < W[j]);
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i ++)
        scanf("%d%d%d", &V[i], &U[i], &W[i]), S[i] = i;
    sort(S, S + m, CMP);
    memset(P, -1, sizeof(P));
    for (int j = 0; j < m; j ++)
    {
        int i = S[j];
        int v = V[i], u = U[i];
        v = Find(v); u = Find(u);
        if (v == u) continue;
        P[v] = u; MST[i] = 1;
    }
    int ts = 0;
    for (int i = 0; i < m; i ++)
        if (!MST[i])
            vec[V[i]].push_back({U[i], ts}), vec[U[i]].push_back({V[i], ts}), ts ++;
    vector < int > res(ts, 0);
    memset(P, -1, sizeof(P));
    for (int j = 0; j < m; j ++)
    {
        int i = S[j];
        int v = V[i], u = U[i], w = W[i];
        v = Find(v); u = Find(u);
        if (v == u) continue;
        if (vec[u].size() > vec[v].size()) swap(v, u);
        for (auto X : vec[u])
        {
            int u = X.first;
            if (Find(u) == v)
                res[X.second] = w;
            else
                vec[v].push_back(X);
        }
        vec[u].clear();
        P[u] = v;
    }
    for (int i = 0; i < ts; i ++)
        printf("%d\n", res[i]);
    return 0;
}