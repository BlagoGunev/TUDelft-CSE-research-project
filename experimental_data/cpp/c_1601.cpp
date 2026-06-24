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



template <typename T>

struct Fenwick {

    int n;

    vector<T> a;

    Fenwick(int n = 0) : n(n), a(n) {}

    void add(int pos, T val) {

        while (pos < n) {

            a[pos] += val;

            pos |= pos + 1;

        }

    }

    T sum(int pos) {

        T res = {};

        while (pos >= 0) {

            res += a[pos];

            pos = (pos & pos + 1) - 1;

        }

        return res;

    }

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



        vector<int> a(n), b(m);

        for (int i = 0; i < n; i++) {

            cin >> a[i];

        }

        for (int i = 0; i < m; i++) {

            cin >> b[i];

        }



        sort(b.begin(), b.end());

        vector<int> p(m);



        auto dc = [&](auto dc, int la, int ra, int lb, int rb) -> void {

            if (rb < lb) {

                return;

            }

            int mb = lb + rb >> 1;

            pair<int, int> res{0, la};

            for (int i = la, inv = 0; i < ra; i++) {

                if (b[mb] < a[i]) {

                    inv++;

                }

                if (b[mb] > a[i]) {

                    inv--;

                }

                res = min(res, {inv, i + 1});

            }

            p[mb] = res.second;

            dc(dc, la, p[mb], lb, mb - 1);

            dc(dc, p[mb], ra, mb + 1, rb);

        };

        dc(dc, 0, n, 0, m - 1);



        vector<int> c;



        for (int i = 0, j = 0; i <= n; i++) {

            while (j < m && p[j] == i) {

                c.push_back(b[j++]);

            }

            if (i < n) {

                c.push_back(a[i]);

            }

        }



        debug(p, c);



        auto sc = c;

        sort(sc.begin(), sc.end());

        reverse(c.begin(), c.end());

        Fenwick<int> f(n + m);

        i64 ans = 0;



        for (auto x : c) {

            int i = lower_bound(sc.begin(), sc.end(), x) - sc.begin();

            ans += f.sum(i - 1);

            f.add(i, 1);

        }



        cout << ans << '\n';

    };



    while (t--) {

        solve();

    }

    

    return 0;

}