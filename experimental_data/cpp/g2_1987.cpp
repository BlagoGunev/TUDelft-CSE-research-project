#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using vll = vector<ll>;
const ll MOD = 1000000007LL;

void solve()
{
    ll n;
    cin >> n;
    vll a(n);
    map<ll, ll, greater<>> mp;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) mp[a[i]] = i + 1;
    string str;
    cin >> str;

    struct Node
    {
        tuple<ll, ll, ll> memo = {-1, -1, -1};
        pll lr;
        vector<pll> adjl;
        vector<pll> adjr;
    };

    set<ll> c;
    c.insert(0);
    c.insert(n + 1);
    vector<Node> graph(n + 1);
    for (auto [val, pos]: mp)
    {
        auto r = c.upper_bound(pos);
        auto l = prev(r);
        if (0 < *r && *r < n + 1) graph[*r].adjl.push_back({pos, str[pos - 1] != 'L'});
        if (0 < *l && *l < n + 1) graph[*l].adjr.push_back({pos, str[pos - 1] != 'R'});
        c.insert(pos);
    }

    ll maxi = 0;
    vll vis(n + 1);
    vis[0] = 1;
    vis[mp.begin()->second] = 1;
    auto comp = [&](auto& comp, ll curr) -> tuple<ll, ll, ll>
    {
        if (get<0>(graph[curr].memo) >= 0) return graph[curr].memo;
        for (auto [t, good]: graph[curr].adjl) comp(comp, t);
        for (auto [t, good]: graph[curr].adjr) comp(comp, t);

        ll dleft = 0, dright = 0;
        ll lpos = 0, rpos = 0;
        if (graph[curr].adjl.size())
        {
            lpos = graph[curr].adjl[0].first;
            dleft = graph[lpos].lr.first;
        }

        if (graph[curr].adjr.size())
        {
            rpos = graph[curr].adjr[0].first;
            dright = graph[rpos].lr.second;
        }

        ll maxl = 0, maxr = 0;
        ll maxleft = 0, maxright = 0;

        for (auto [t, good]: graph[curr].adjl)
        {
            auto [l, r, d] = comp(comp, t);
            if (good) vis[t] = 1;
            if (t == lpos) graph[curr].lr.first = max(dleft, (str[lpos - 1] != 'R') * d);
            if (t == lpos && good) maxleft = max(maxleft, l + 1);
            if (good) maxl = max(maxl, d), maxi = max(maxi, r);
            if (t == lpos && str[t - 1] != 'R') maxleft = max(maxleft, r + 1);
            if (good && t != lpos) maxleft = max(maxleft, d + dleft + 1);
        }

        for (auto [t, good]: graph[curr].adjr)
        {
            auto [l, r, d] = comp(comp, t);
            if (good) vis[t] = 1;
            if (t == rpos) graph[curr].lr.second = max(dright, (str[rpos - 1] != 'L') * d);
            if (t == rpos && good) maxright = max(maxright, r + 1);
            if (good) maxr = max(maxr, d), maxi = max(maxi, l);
            if (t == rpos && str[t - 1] != 'L') maxright = max(maxright, l + 1);
            if (good && t != rpos) maxright = max(maxright, d + dright + 1);
        }

        ll d = max(maxl, maxr) + 1;
        maxi = max({maxi, maxl + maxr});
        maxleft = max(maxleft, maxr + 1 + graph[curr].lr.first);
        maxright = max(maxright, maxl + 1 + graph[curr].lr.second);
        graph[curr].memo = {maxleft, maxright, d};
        return graph[curr].memo;
    };

    comp(comp, mp.begin()->second);

    if (std::count(vis.begin(), vis.end(), 0LL))
    {
        cout << -1 << '\n';
        return;
    }

    cout << maxi << '\n';
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    ll t;
    cin >> t;
    while (t--) solve();
}