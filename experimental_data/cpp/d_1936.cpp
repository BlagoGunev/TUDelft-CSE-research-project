#include<iostream>
#include<vector>
#include<random>
#include<algorithm>
#include<map>
#include<set>
#include<random>
#include<chrono>

#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define ld long double

using namespace std;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rnd64(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = 200005;
const int INF = 2e9;

struct node
{
    int mx, val;

    node()
    {
        mx = -1; val = 0;
    }
    node(pair<int, int> x)
    {
        mx = x.fi; val = x.se;
    }
};

node cmb(node a, node b)
{
    node c;
    c.mx = max(a.mx, b.mx);
    c.val = a.val | b.val;
    return c;
}

node tre1[MAXN*4];
pair<int, int> dat[MAXN];

void Build(int l, int r, int v)
{
    if(l == r)
    {
        tre1[v] = node(dat[l]);
        return;
    }
    int m = (l+r) / 2;
    Build(l, m, v*2);
    Build(m+1, r, v*2+1);
    tre1[v] = cmb(tre1[v*2], tre1[v*2+1]);
}

int Max(int l, int r, int L, int R, int v)
{
    if(l >= L && r <= R)
        return tre1[v].mx;
    if(l > R || r < L)
        return -1;
    int m = (l+r) / 2;
    return max(Max(l, m, L, R, v*2), Max(m+1, r, L, R, v*2+1));
}

pair<int, int> FindFs1(int l, int r, int L, int R, int v, int val, int x)
{
    if(L == -1)
    {   
        if(l == r)
        {
            if((tre1[v].val | val) > x)
                return {l, tre1[v].val | val};
            return {INF, tre1[v].val | val};
        }
        int m = (l+r) / 2;
        if((tre1[v*2].val | val) > x)
            return FindFs1(l, m, L, R, v*2, val, x);
        else
            return FindFs1(m+1, r, L, R, v*2+1, val | tre1[v*2].val, x);
    }
    if(l >= L && r <= R)
    {
        if((tre1[v].val | val) > x)
            return FindFs1(l, r, -1, -1, v, val, x);
        else
            return {INF, tre1[v].val | val};
    }
    if(l > R || r < L)
        return {INF, val};
    int m = (l+r) / 2;
    auto res = FindFs1(l, m, L, R, v*2, val, x);
    if(res.fi != INF)
        return res;
    return FindFs1(m+1, r, L, R, v*2+1, res.se, x);
}

pair<int, int> FindFs2(int l, int r, int L, int R, int v, int val, int x)
{
    if(L == -1)
    {   
        if(l == r)
        {
            if((tre1[v].val | val) > x)
                return {l, tre1[v].val | val};
            return {-1, tre1[v].val | val};
        }
        int m = (l+r) / 2;
        if((tre1[v*2+1].val | val) > x)
            return FindFs2(m+1, r, L, R, v*2+1, val, x);
        else
            return FindFs2(l, m, L, R, v*2, val | tre1[v*2+1].val, x);
    }
    if(l >= L && r <= R)
    {
        if((tre1[v].val | val) > x)
            return FindFs2(l, r, -1, -1, v, val, x);
        else
            return {-1, tre1[v].val | val};
    }
    if(l > R || r < L)
        return {-1, val};
    int m = (l+r) / 2;
    auto res = FindFs2(m+1, r, L, R, v*2+1, val, x);
    if(res.fi != -1)
        return res;
    return FindFs2(l, m, L, R, v*2, res.se, x);
}

void Set(int l, int r, int v, int i, pair<int, int> x)
{
    if(l == r)
    {
        tre1[v] = node(x);
        return;
    }
    int m = (l+r) / 2;
    if(i <= m)
        Set(l, m, v*2, i, x);
    else
        Set(m+1, r, v*2+1, i, x);
    tre1[v] = cmb(tre1[v*2], tre1[v*2+1]);
}

int V;
int n;

struct Data
{
    int mx, val;
    int l, r;
    int ans;
    vector<pair<int, int> > chngL, chngR;

    Data()
    {
        chngL = chngR = vector<pair<int, int> >();
        mx = 0; val = 0;
        l = r = -1;
        ans = INF;
    }
    Data(pair<int, int> x, int L, int R)
    {
        l = L; r = R;
        mx = x.fi;
        val = x.se;
        chngL = vector<pair<int, int> > (1, {mx, val});
        chngR = vector<pair<int, int> > (1, {mx, val});
        if(x.se >= V)
            ans = x.fi;
        else
            ans = INF;
        
    }
};

inline Data cmb(Data a, Data b)
{
    if(a.l == -1) return b;
    if(b.l == -1) return a;
    Data c;
    c.mx = max(a.mx, b.mx);
    c.val = a.val | b.val;
    c.l = a.l;
    c.r = b.r;

    c.ans = min(a.ans, b.ans);
    int ps = a.chngR.size()-1;
    for(auto i : b.chngL)
    {
        while(ps && (a.chngR[ps-1].se | i.se) >= V)
            ps--;
        if((a.chngR[ps].se | i.se) >= V)
        {
            c.ans = min(c.ans, max(a.chngR[ps].fi, i.fi));
        }
    }

    c.chngL = vector<pair<int, int> >(a.chngL);
    int val = a.val, mx = a.mx, prv = val;
    for(auto i : b.chngL)
    {
        if((i.se | val) != prv)
        {
            c.chngL.push_back({max(i.fi, mx), i.se | val});
            prv = (i.se | val);
        }
    }
    c.chngR = vector<pair<int, int> >(b.chngR);
    val = b.val; mx = b.mx; prv = val;
    for(auto i : a.chngR)
    {
        if((i.se | val) != prv)
        {
            c.chngR.push_back({max(i.fi, mx), i.se | val});
            prv = (i.se | val);
        }
    }
    return c;
}

Data tre2[MAXN*4];

void Build2(int l, int r, int v)
{
    if(l == r)
    {
        tre2[v] = Data(dat[l], l, r);
        return;
    }
    int m = (l+r) / 2;
    Build2(l, m, v*2);
    Build2(m+1, r, v*2+1);
    tre2[v] = cmb(tre2[v*2], tre2[v*2+1]);
}

void Set2(int l, int r, int v, int i, pair<int, int> x)
{
    if(l == r)
    {
        tre2[v] = Data(x, l, r);
        return;
    }
    int m = (l+r) / 2;
    if(i <= m)
        Set2(l, m, v*2, i, x);
    else
        Set2(m+1, r, v*2+1, i, x);
    tre2[v] = cmb(tre2[v*2], tre2[v*2+1]);
}

Data GetAns(int l, int r, int L, int R, int v)
{
    if(l >= L && r <= R)
        return tre2[v];
    if(l > R || r < L)
        return Data();
    int m = (l+r) / 2;
    return cmb(GetAns(l, m, L, R, v*2), GetAns(m+1, r, L, R, v*2+1));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    while(T--)
    {
        cin >> n >> V;
        for(int i = 0; i < n; i++)
        {
            cin >> dat[i].fi;
        }
        for(int i = 0; i < n; i++)
        {
            cin >> dat[i].se;
        }
        Build2(0, n-1, 1);
        int q; cin >> q;
        for(int i = 0; i < q; i++)
        {
            int t; cin >> t;
            if(t == 1)
            {
                int v, x; cin >> v >> x; v--;
                Set2(0, n-1, 1, v, {dat[v].fi, x});
            }
            else
            {
                int l, r; cin >> l >> r; l--; r--;
                auto res = GetAns(0, n-1, l, r, 1);
                ll ans = res.ans;
                if(ans == INF)
                    ans = -1;
                cout << ans << ' ';
            }
        }
        cout << '\n';
    }
}   
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

/// shche ne vmerla Ykraina