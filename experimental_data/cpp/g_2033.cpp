#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
#define LL long long
#define pLL pair<LL, LL>
#define F first
#define S second
#define pb push_back
#define rz resize
#define all(x) x.begin(), x.end()
#define CH cout << "I am here!" << endl;

// here!!!
#define DEBU

#ifndef DEBUG
#define endl '\n'
#endif
const long long inv2 = 500000004; // mod 1e9 + 7
const long long MOD = 1e9 + 7;
const long long INF = __LONG_LONG_MAX__;
const long long N = 2e5 + 1;
void Motto_Hayaku()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
template <typename T>
void ls(T &v)
{
    for (auto i : v)
        cout << i << " ";
    cout << endl;
}
template <typename T, typename... Args>
void ls(T &v, const Args &...args)
{
    for (auto i : v)
        cout << i << " ";
    cout << endl;
    ls(args...);
}

struct seg
{
    LL l, r, v;
    seg *ln, *rn;
    seg(LL ll, LL rr) : l(ll), r(rr)
    {
        if (l != r - 1)
        {
            LL m = (l + r) >> 1;
            ln = new seg(l, m);
            rn = new seg(m, r);
            v = comb(ln->v, rn->v);
        }
        else
        {
            v = 0;
        }
        return;
    }
    LL comb(LL a, LL b)
    {
        return max(a, b);
    }
    LL ask(LL ll, LL rr)
    {
        if (l == ll && r == rr)
        {
            return v;
        }
        LL m = (l + r) >> 1;
        if (m >= rr)
        {
            return ln->ask(ll, rr);
        }
        else if (m <= ll)
        {
            return rn->ask(ll, rr);
        }
        else
        {
            return comb(ln->ask(ll, m), rn->ask(m, rr));
        }
    }

    void revise(LL tar, LL value)
    {
        if (tar == l && tar == r - 1)
        {
            v = value;
            return;
        }
        else
        {
            LL m = (l + r) >> 1;
            if (tar < m)
            {
                ln->revise(tar, value);
            }
            else
            {
                rn->revise(tar, value);
            }
            v = comb(ln->v, rn->v);
        }
    }
};
void sol()
{
    LL n;
    cin >> n;
    vector<vector<LL>> p(n);

    for (int i = 0; i < n - 1; i++)
    {
        LL a, b;
        cin >> a >> b;
        a--;
        b--;
        p[a].pb(b);
        p[b].pb(a);
    }
    int q;
    cin >> q;
    vector<vector<pLL>> qu(n);
    vector<int> ans(q);
    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        qu[a].pb({b, i});
    }
    vector<pLL> dp(n, {0, 0}), idx(n, {-1, -1});
    auto cmp = [&](int p, int q)
    {
        pLL a = {dp[p].F, idx[p].F};
        pLL b = {dp[p].S, idx[p].S};
        pLL c = {dp[q].F + 1, q};
        vector<pLL> tmp = {a, b, c};
        sort(all(tmp));
        return make_pair(tmp[2], tmp[1]);
    };
    function<void(LL, LL)>
        cal = [&](LL pos, LL prev)
    {
        for (auto i : p[pos])
        {
            if (i == prev)
                continue;
            cal(i, pos);
            auto tmp = cmp(pos, i);
            dp[pos] = {tmp.F.F, tmp.S.F};
            idx[pos] = {tmp.F.S, tmp.S.S};
        }
    };
    cal(0, 0);
    seg tr(0, n + 1);
    function<void(LL, LL, LL)> dfs = [&](LL pos, LL prev, LL dep)
    {
        for (auto i : p[pos])
        {
            if (i == prev)
                continue;
            if (i == idx[pos].F)
            {
                tr.revise(dep, dp[pos].S - dep);
            }
            else
            {
                tr.revise(dep, dp[pos].F - dep);
            }
            dfs(i, pos, dep + 1);
        }
        tr.revise(dep, dp[pos].F - dep);
        for (auto a : qu[pos])
        {
            ans[a.S] = tr.ask(max(0ll, dep - a.F), dep + 1) + dep;
        }
    };
    dfs(0, 0, 0);
    ls(ans);
}
int main()
{
    Motto_Hayaku();
    LL t = 1;
    cin >> t;
    while (t--)
    {
        sol();
    }
#ifdef DEBUG
    system("pause");
#endif
    return 0;
}