#include <bits/stdc++.h>
#include <chrono>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define deb(x...)
#endif
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef long long ll;
#define range(x, n) for (int x = 0; x < n; x++)
// #define range(x, s, n) for (int x = s; x < n; x++)
#define all(v) v.begin(), v.end()
#define CHECK_BIT(var, pos) ((var >> pos) & (1ll))
#define SET_BIT(var, pos) (var |= (1ll << pos))
#define int ll
int GET_BIT_BASE(int var, int pos, int base = 2)
{
    return (var % (int)pow(base, pos + 1)) / pow(base, pos);
}
void SET_BIT_BASE(int &var, int pos, int val, int base = 2)
{
    var += (val - GET_BIT_BASE(var, pos, base)) * pow(base, pos);
}
struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
template <typename U, typename T>
using umap = unordered_map<U, T, custom_hash>;
template <typename U>
using uset = unordered_set<U, custom_hash>;
const int mod = 1e9 + 7ll;
const int INF = 9e18;
const int M = 998244353;
template <typename T>
inline int sgn(T val)
{
    return (T(0) < val) - (val < T(0));
}
int dirx[4] = {1, 0, -1, 0};
int diry[4] = {0, 1, 0, -1};
// vector<char> pat = {'D', 'R', 'U', 'L'};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    int l = INT_MAX, h = 0;
    range(_, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        l = min(w, l);
        h = max(w, h);
    }
    function<bool(int, int, vector<int> &, vector<int> &, vector<int> &, vector<int> &, int &)> dfs1 =
        [&](int node, int par, vector<int> &state, vector<int> &stk, vector<int> &pref, vector<int> &mm, int &xx)
    {
        for (auto &[a, w] : adj[node])
        {
            if (a == par or state[a] == 2)
                continue;
            if (state[a] == 1)
            {
                if ((w <= xx) or ((pref[stk.size() - 1] - pref[mm[a]]) > 0))
                {
                    stk.push_back(a);
                    return true;
                }
                continue;
            }
            state[a] = 1;
            stk.push_back(a);
            mm[a] = stk.size() - 1;
            pref[stk.size() - 1] = pref[stk.size() - 2];
            if (w <= xx)
                pref[stk.size() - 1]++;
            if (dfs1(a, node, state, stk, pref, mm, xx))
                return true;
            state[a] = 2;
            stk.pop_back();
        }
        return false;
    };
    function<bool(int)> possible = [&](int xx) { // 0-unvisited, 1-in_stack, 2-done;
        vector<int> state(n), stk, pref(n + 1), mm(n);

        range(x, n)
        {
            if (state[x] == 0)
            {
                state[x] = 1;
                stk.push_back(x);
                mm[x] = 0;
                if (dfs1(x, -1, state, stk, pref, mm, xx))
                    return true;
                state[x] = 2;
                stk.pop_back();
            }
        }
        return false;
    };
    while (l < h)
    {
        int m = l + (h - l) / 2;
        if (possible(m))
            h = m;
        else
            l = m + 1;
    }
    deb(l);
    vector<int> state(n), stk, pref(n + 1), mm(n);

    range(x, n)
    {
        if (state[x] == 0)
        {
            state[x] = 1;
            stk.push_back(x);
            mm[x] = 0;
            if (dfs1(x, -1, state, stk, pref, mm, l))
            {
                int r = stk.back();
                stk.pop_back();
                vector<int> res;
                while (stk.back() != r)
                {
                    res.push_back(stk.back());
                    stk.pop_back();
                }
                res.push_back(r);
                cout << l << " " << res.size() << endl;
                for (auto &a : res)
                    cout << a + 1 << " ";
                cout << endl;
                return;
            }
            state[x] = 2;
            stk.pop_back();
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    start = std::chrono::high_resolution_clock::now();
#endif

    ll t;
    cin >> t;
    while (t--)
        solve();

#ifndef ONLINE_JUDGE
    end = std::chrono::high_resolution_clock::now();
    ll elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    cout << "\nTime: " << elapsed_time << "ms\n";

    switch (__cplusplus)
    {
    case 202002:
        cout << "C++20";
        break;
    case 201703:
        cout << "C++17";
        break;
    case 201402:
        cout << "C++14";
        break;
    case 201103:
        cout << "C++11";
        break;
    case 199711:
        cout << "C++98";
        break;
    case 1:
        cout << "C++ pre - C++98";
        break;
    default:
        cout << "Unknown: " << __cplusplus;
        break;
    }
#endif
    return 0;
}