#include <algorithm>

#include <cassert>

#include <cstdio>

#include <cstring>

#include <iomanip>

#include <iostream>

#include <map>

#include <numeric>

#include <queue>

#include <ranges>

#include <set>

#include <string>

#include <vector>



using namespace std;



#define all(x) (x).begin(), (x).end()

#define rall(x) (x).rbegin(), (x).rend()



void __print(int x) { cerr << x; }

void __print(long x) { cerr << x; }

void __print(long long x) { cerr << x; }

void __print(unsigned x) { cerr << x; }

void __print(unsigned long x) { cerr << x; }

void __print(unsigned long long x) { cerr << x; }

void __print(float x) { cerr << x; }

void __print(double x) { cerr << x; }

void __print(long double x) { cerr << x; }

void __print(char x) { cerr << '\'' << x << '\''; }

void __print(const char *x) { cerr << '\"' << x << '\"'; }

void __print(const string &x) { cerr << '\"' << x << '\"'; }

void __print(bool x) { cerr << (x ? "true" : "false"); }



template <typename T, typename V>

void __print(const pair<T, V> &x) {

    cerr << '{';

    __print(x.first);

    cerr << ',';

    __print(x.second);

    cerr << '}';

}

template <typename T>

void __print(const T &x) {

    int f = 0;

    cerr << '{';

    for (auto &i : x) cerr << (f++ ? "," : ""), __print(i);

    cerr << "}";

}

void _print() { cerr << "]\n"; }

template <typename T, typename... V>

void _print(T t, V... v) {

    __print(t);

    if (sizeof...(v)) cerr << ", ";

    _print(v...);

}

#ifdef DUPA

#define debug(x...)               \

    cerr << "[" << #x << "] = ["; \

    _print(x)

#else

#define debug(x, ...)

#endif



typedef long long LL;

// HMMMM

#define int LL



typedef pair<int, int> PII;

typedef pair<int, PII> PIII;



const int INF = 1e9 + 1;



int n, m;

int x, k, y;

vector<int> a, b;



int f(int l, int r) {

    assert(l < r);

    int mx = *max_element(a.begin() + l, a.begin() + r + 1);



    bool mx_outside = a[l] == mx || a[r] == mx;

    int w = r - l - 1;

    if (w == 0) return 0;

    int kill_k = min(x, k * y);



    int res = 0;



    if (!mx_outside) {

        if (w < k) return -1;

        w -= k;

        res += x;

    }



    res += (w / k) * kill_k + (w % k) * y;

    return res;

}



int solve() {

    cin >> n >> m;

    cin >> x >> k >> y;

    a.resize(n);

    b.resize(m);



    for (int i = 0; i < n; i++) {

        cin >> a[i];

        a[i] += 2;

    }

    for (int i = 0; i < m; i++) {

        cin >> b[i];

        b[i] += 2;

    }



    if (m > n) return -1;



    a.insert(a.begin(), 0);

    a.push_back(1);



    b.insert(b.begin(), 0);

    b.push_back(1);



    n += 2;

    m += 2;



    vector<int> rev_a(n + 1, -1);

    for (int i = 0; i < n; i++) {

        assert(rev_a[a[i]] == -1);

        rev_a[a[i]] = i;

    }



    for (int i = 0; i < m; i++)

        if (rev_a[b[i]] == -1) return -1;



    int res = 0;



    for (int i = 1; i < m; i++) {

        if (rev_a[b[i - 1]] >= rev_a[b[i]]) return -1;

        int curr = f(rev_a[b[i - 1]], rev_a[b[i]]);

        if (curr == -1) return -1;

        res += curr;

    }



    return res;

}



#undef int

int main() {

    ios::sync_with_stdio(false);

    cin.exceptions(cin.failbit);



    cin.tie(0);

    int t = 1;

#ifdef DUPA

    cin >> t;

#endif

    for (int i = 0; i < t; i++) cout << solve() << "\n";

}