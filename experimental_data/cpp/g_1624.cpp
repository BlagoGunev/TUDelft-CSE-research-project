#include <bits/stdc++.h>

using namespace std;



using i64 = long long;



template <typename A, typename B>

string to_string(pair<A, B> p);

 

template <typename A, typename B, typename C>

string to_string(tuple<A, B, C> p);

 

template <typename A, typename B, typename C, typename D>

string to_string(tuple<A, B, C, D> p);

 

string to_string(const string& s) {

    return '"' + s + '"';

}

 

string to_string(const char* s) {

    return to_string((string) s);

}

 

string to_string(bool b) {

    return (b ? "true" : "false");

}

 

string to_string(vector<bool> v) {

    bool first = true;

    string res = "{";

    for (int i = 0; i < static_cast<int>(v.size()); i++) {

        if (!first) {

            res += ", ";

        }

        first = false;

        res += to_string(v[i]);

    }

    res += "}";

    return res;

}

 

template <size_t N>

string to_string(bitset<N> v) {

    string res = "";

    for (size_t i = 0; i < N; i++) {

        res += static_cast<char>('0' + v[i]);

    }

    return res;

}

 

template <typename A>

string to_string(A v) {

    bool first = true;

    string res = "{";

    for (const auto &x : v) {

        if (!first) {

            res += ", ";

        }

        first = false;

        res += to_string(x);

    }

    res += "}";

    return res;

}

 

template <typename A, typename B>

string to_string(pair<A, B> p) {

    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";

}

 

template <typename A, typename B, typename C>

string to_string(tuple<A, B, C> p) {

    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";

}

 

template <typename A, typename B, typename C, typename D>

string to_string(tuple<A, B, C, D> p) {

    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";

}

 

void debug_out() { cout << endl; }

 

template <typename Head, typename... Tail>

void debug_out(Head H, Tail... T) {

    cout << " " << to_string(H);

    debug_out(T...);

}

 

#ifdef LOCAL

#define debug(...) cout << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

#else

#define debug(...) 42

#endif



struct DSU {

    int n, comps;

    vector<int> fa, sz;

    DSU(int n = 0) : n(n), comps(n), fa(n), sz(n, 1) { iota(fa.begin(), fa.end(), 0); }

    int find(int u) { return u == fa[u] ? u : fa[u] = find(fa[u]); }

    bool join(int u, int v) {

        u = find(u), v = find(v);

        if (u != v) {

            if (sz[u] < sz[v]) swap(u, v);

            sz[u] += sz[v];

            fa[v] = u;

            comps--;

            return true;

        }

        return false;

    }

    bool same(int u, int v) { return find(u) == find(v); }

    int size(int u) { return sz[find(u)]; }

};



int main() {

    cin.tie(nullptr)->sync_with_stdio(false);



#ifdef LOCAL

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);

#endif



    int t;

    cin >> t;



    auto solve = [&]() {

        int n, m;

        cin >> n >> m;



        vector<array<int, 3>> e(m);

        for (auto &[w, u, v] : e) {

            cin >> u >> v >> w;

            u--, v--;

        }



        sort(e.begin(), e.end());



        int ans = 0;



        for (int i = 29; i >= 0; i--) {

            DSU d(n);

            for (auto [w, u, v] : e) {

                if (~w >> i & 1) {

                    d.join(u, v);

                }

            }

            if (d.comps == 1) {

                e.erase(remove_if(e.begin(), e.end(), [&](auto x) {

                    return x[0] >> i & 1;

                }), e.end());

            } else {

                ans |= 1 << i;

            }

        }



        cout << ans << '\n';

    };



    while (t--) {

        solve();

    }

    

    return 0;

}