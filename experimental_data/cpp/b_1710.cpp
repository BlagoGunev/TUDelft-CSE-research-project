#include<bits/stdc++.h>



#define debug(x) cerr << #x << " = " << x << '\n';



using namespace std;



typedef long long ll;



const int inf = 0x3f3f3f3f;

const ll INF = 0x3f3f3f3f3f3f3f3f;

const ll mod = 998244353;

const int N = 3e5 + 10;



struct node {

    ll pos, tag;

};



void solve() {

    ll n, m;

    cin >> n >> m;

    vector<ll> x(n + 1), p(n + 1);

    vector<node> v;



    for (int i = 1; i <= n; ++i) {

        cin >> x[i] >> p[i];

        ll l = x[i] - p[i] + 1, m = x[i] + 1, r = x[i] + p[i] + 1;

        v.push_back({l, 1});

        v.push_back({m, -2});

        v.push_back({r, 1});

    }



    sort(v.begin(), v.end(), [&](node &a, node &b) {

        if (a.pos == b.pos) return a.tag < b.tag;

        return a.pos < b.pos;

    });



    // ll mx1 = 0, mx2 = 0;

    // auto modify = [&](ll pos, ll pre) {

    //     mx1 = max(mx1, pre + pos - m);

    //     mx2 = max(mx2, pre - pos - m); 

    // };

    ll mx = -INF, mi = INF;

    auto modify = [&](ll id, ll val) {

        if (val <= m) return;

        mx = max(mx, id + val - m);

        mi = min(mi, id - val + m);

    };



    v.push_back({INF, 0});

    ll pre = 0;

    vector<ll> d(3 * n + 1);

    for (int i = 0; i < v.size() - 1; ++i) {

        if (i == 0) d[i] = v[i].tag;

        else d[i] = d[i - 1] + v[i].tag;

        // debug(d[i]);



        if (v[i].pos != v[i + 1].pos) {

            modify(v[i].pos, pre + d[i]);

            modify(v[i + 1].pos - 1, pre + d[i] * (v[i + 1].pos - v[i].pos));

        }

        pre += d[i] * (v[i + 1].pos - v[i].pos);

    }

    for (int i = 1; i <= n; ++i) {

        if (mx <= p[i] + x[i] && mi >= x[i] - p[i]) cout << 1;

        else cout << 0;

    }

    cout << '\n';

}







/*

x[i]-p[i]+1 += 1

x[i] -= 2

x[i]+p[i]+1 += 1

0 1 2 3 4  3  2  1  0 0

0 1 1 1 1 -1 -1 -1 -1 0

0 1 0 0 0 -2  0  0  0 1

对于[xi, pi]

max(0, pi - |xi - id|)

假如id > xi，原本位置上的数是 val

val - max(0, pi + xi - id) <= m

val + id - m <= pi + xi

假如id < xi 

val - max(0, pi - xi + id) <= m

val - id - m <= pi - xi;

*/



int main() {

    ios::sync_with_stdio(false);cin.tie(nullptr),cout.tie(nullptr);

    int t = 1;

    cin >> t;

    while(t--) {

        solve();

    }

    return 0;

}