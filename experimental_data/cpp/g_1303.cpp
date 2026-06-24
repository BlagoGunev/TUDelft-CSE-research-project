#include <bits/stdc++.h>

#define task ""

#define fi first

#define se second

#define int long long

#define fori(i, L, R) for(auto i = (L); i <= (R); ++i)

#define ford(i, L, R) for(auto i = (L); i >= (R); --i)

using namespace std;



void Freopen()

{

    if(fopen(task".inp","r"))

    {

        freopen(task".inp","r",stdin);

        freopen(task".out","w",stdout);

    }

}



const int maxn = 150005;

typedef long long LL;

typedef pair <LL, LL> L4;



struct lichao

{

    int childL, childR;

    long long L, R, mid;

    L4 line;

};



long long val(long long x, L4 line)

{

    return line.fi * x + line.se;

}



int nT;

lichao tree[maxn * 4];



void newnode(int r, long long k, long long l)

{

    tree[r].childL = tree[r].childR = 0;

    tree[r].line = L4(0, 0);

    tree[r].L = k; tree[r].R = l;

    tree[r].mid = (k + l)/2;

}



void add(int r, L4 newL)

{

    bool tL, tR, tM;



    tL = (val(tree[r].L, newL) <= val(tree[r].L, tree[r].line));

    tR = (val(tree[r].R, newL) <= val(tree[r].R, tree[r].line));

    if(tL && tR)

        return;



    tL = (val(tree[r].L, newL) >= val(tree[r].L, tree[r].line));

    tR = (val(tree[r].R, newL) >= val(tree[r].R, tree[r].line));

    if(tL && tR)

    {

        tree[r].line = newL;

        return;

    }



    tM = (val(tree[r].mid, newL) >= val(tree[r].mid, tree[r].line));



    if(tM)

        swap(newL,tree[r].line);



    if(tree[r].L == tree[r].R)

        return;



    if(tL != tM)

    {

        if(!tree[r].childL)

        {

            tree[r].childL = ++nT;

            newnode(nT, tree[r].L, tree[r].mid);

        }

        add(tree[r].childL, newL);

    }

    else

    {

        if(!tree[r].childR)

        {

            tree[r].childR = ++nT;

            newnode(nT, tree[r].mid + 1, tree[r].R);

        }

        add(tree[r].childR, newL);

    }

}



LL get(int r, LL x)

{

    LL res = val(x, tree[r].line);

    if(x <= tree[r].mid)

    {

        if(tree[r].childL)

            res = max(res, get(tree[r].childL, x));

    }

    else

    {

        if(tree[r].childR)

            res = max(res, get(tree[r].childR, x));

    }

    return res;

}



int n, a[maxn];

vector <int> g[maxn];



void Inp()

{

    scanf("%lld",&n);

    fori(i, 2, n)

    {

        int u, v;

        scanf("%lld%lld",&u,&v);

        g[u].push_back(v);

        g[v].push_back(u);

    }

    fori(i, 1, n)

        scanf("%lld",&a[i]);

}



int flag, cl[maxn], s[maxn];



void dfssize(int u)

{

    cl[u] = flag;

    s[u] = 1;

    for(int v : g[u])

        if(cl[v] >= 0 && cl[v] != flag)

        {

            dfssize(v);

            s[u] += s[v];

        }

}



int r, depth[maxn], q[maxn], root;

long long sum[maxn], kc[maxn], d[maxn], res;



void dfs(int u, int dad)

{

    q[++r] = u;

    depth[u] = depth[dad] + 1;

    sum[u] = sum[dad] + a[u];

    kc[u] = kc[dad] + sum[u];

    d[u] = d[dad] + 1ll * (depth[u] + 1) * a[u];



    res = max(res, kc[u] + a[root]);

    res = max(res, d[u] + get(0, sum[u]));



    for(int v : g[u])

        if(cl[v] != -1 && v  != dad)

            dfs(v, u);

}



void centroid(int u)

{

    ++flag;

    dfssize(u);

    int smax = s[u];

    int cen = u, vmax;

    while(1)

    {

        --cl[cen];

        vmax = 0;

        for(int v : g[cen])

            if(s[v] * 2 > smax && cl[v] == flag)

            {

                vmax = v;

                break;

            }

        if(vmax > 0)

            cen = vmax;

        else

            break;

    }



    root = cen;

    kc[cen] = 0;

    cl[cen] = -1;

    d[cen] = sum[cen] = 1ll * a[cen];

    depth[cen] = 0;



    res = max(res, 1ll * a[cen]);



    newnode(0, 1, 2e16);

    for(int v : g[cen])

        if(cl[v] != -1)

        {

            dfs(v, cen);

            while(r > 0)

            {

                int x = q[r];

                add(0, L4(depth[x], kc[x] - depth[x] * a[root]));

                --r;

            }

        }



    reverse(g[cen].begin(),g[cen].end());

    newnode(0, 1, 2e16);

    for(int v : g[cen])

        if(cl[v] != -1)

        {

            dfs(v, cen);

            while(r > 0)

            {

                int x = q[r];

                add(0, L4(depth[x], kc[x] - depth[x] * a[root]));

                --r;

            }

        }



    for(int v : g[cen])

        if(cl[v] != -1)

            centroid(v);

}



int32_t main()

{

    Freopen();

    Inp();

    res = 0;

    centroid(1);

    printf("%lld",res);

}