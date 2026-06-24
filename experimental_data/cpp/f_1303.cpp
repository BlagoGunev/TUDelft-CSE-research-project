#include <iostream>

#include <iomanip>

#include <ostream>

#include <istream>

#include <set>

#include <unordered_set>

#include <map>

#include <unordered_map>

#include <bitset>

#include <vector>

#include <string>

#include <stack>

#include <queue>

#include <deque>

#include <array>

#include <algorithm>

#include <functional>

#include <cmath>

#include <time.h>

#include <random>

#include <chrono>

#include <cassert>

#include <cstring>

#include <limits>

#include <algorithm>

#include <iomanip>

#include <iostream>

#include <list>

#include <numeric>

#include <random>

#include <vector>

using namespace std;



#define sz(v) ((int)(v).size())

#define all(a) (a).begin(),  (a).end()

#define rall(a) a.rbegin(), a.rend()

#define F first

#define S second

#define rep(i, n) for(int i = 0;i < n;i++)

#define time clock() / (double) CLOCKS_PER_SEC



using pii = pair<int, int>;

using ll = long long;

using ld = long double;



const ll infll = (ll)4e18 + 27;

const ll inf = (ll)1e9 + 27;

const ll mod = (ll)1e9 + 7;



#define dbg(x) cout << #x << " = " << (x) << endl



template <typename T, typename T2>

istream& operator>> (istream& in, pair<T, T2>& b) {

    in >> b.first >> b.second;

    return in;

}



template <typename T, typename T2>

ostream& operator<< (ostream& out, const pair<T, T2>& b) {

    out << "{" << b.first << ", " << b.second << "}";

    return out;

}



template <typename T>

istream& operator>> (istream& in, vector<T>& b) {

    for (auto& v : b)

        in >> v;

    return in;

}



template <typename T>

ostream& operator<< (ostream& out, vector<T>& b) {

    for (auto v : b)

        out << v << ' ';

    return out;

}



template <typename T>

void print(T x, string end = "\n") {

    cout << x << end;

}



template <typename T1, typename T2> bool chkmin(T1& x, const T2& y) { return x > y && (x = y, true); }

template <typename T1, typename T2> bool chkmax(T1& x, const T2& y) { return x < y && (x = y, true); }



mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());



const int N = 310;

int a[N][N];

const int K = 2e6 + 10;

vector<pii> del[K];

vector<pii> add[K];

int sub[K];

struct dsu {

    vector<int> d, p;

    int n = 1;

    void init(int k){

        n = k;

        d.assign(n, 1);

        p.assign(n, 0);

        iota(all(p), 0ll);

    }

    int find(int u){

        if(u == p[u])return u;

        return p[u] = find(p[u]);

    }

    void unite(int u, int v){

        u = find(u);

        v = find(v);

        if(u == v)return;

        if(d[u] < d[v])swap(u, v);

        d[u] += d[v];

        p[v] = u;

    }

};

dsu d;

int n, m;

int dx[4] = {-1, 1, 0, 0};

int dy[4] = {0, 0, 1, -1};

void calculate(vector<pii> &event, int coefficient){

    for(auto [xy, index]: event){

        int current = 1;

        int x = xy / m, y = xy % m;

        a[x][y] = 1;

        for(int j = 0;j < 4;j++){

            int nx = x + dx[j], ny = y + dy[j];

            if(nx >= 0 && nx < n && ny >= 0 && ny < m && a[nx][ny] == 1 &&  d.find(nx * m + ny) != d.find(x * m + y)){

                current--;

                d.unite(nx * m + ny, x * m + y);

            }

        }

        sub[index] += current * coefficient;

    }

    for(auto [xy, index]: event){

        d.d[xy] = 1;

        d.p[xy] = xy;

        a[xy / m][xy % m] = 0;

    }

}



void solve() {

    cin >> n >> m;

    d.init(K);

    int q;

    cin >> q;

    for(int i = 0;i < q;i++){

        int x, y, c;

        cin >> x >> y >> c;

        x--;y--;

        if(a[x][y] == c)continue;

        add[c].push_back({x * m + y, i});

        del[a[x][y]].push_back({x * m + y, i});

        a[x][y] = c;

    }

    for(int i = 0;i < n;i++)

        for(int j = 0;j < m;j++)

            del[a[i][j]].push_back({i * m + j, q});

    for(int i = 0;i < n;i++) for(int j = 0;j < m;j++) a[i][j] = 0;

    for(int i = 0;i < K;i++)

        reverse(all(del[i]));

    for(int i = 0;i < K;i++){

        calculate(add[i], 1);

    }

    for(int i = 0;i < K;i++){

        calculate(del[i], -1);

    }

    int ans = 1;

    for(int i = 0;i < q;i++){

        ans += sub[i];

        cout << ans << "\n";

    }

}



signed main() {

    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout << fixed << setprecision(15);

    int test = 1;

    //cin >> test;

    while (test--)

        solve();

#ifdef home

    cout << "_________________________________" << endl;

    cout << "finished in " << time << " s";

#endif

    return 0;

}

/*

6 9 3

1 9 1

3 8 1

6 9 1

 */