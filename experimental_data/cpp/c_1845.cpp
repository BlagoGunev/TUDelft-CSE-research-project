#include <bits/stdc++.h>

#define f first
#define s second

//#define int li

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using pli = pair<li, li>;
using uli = li;

const int INF = 2e9 + 13;
const li INF64 = 4e18 + 13;
const int M = 998244353;
//const li M = 1'111'111'111'111'111'111ll;
//const int M = 1e9 + 7;
const int A = 200 + 13;

const int LOGN = 18;
//const int N = (1 << LOGN);
const int N = 5e6 + 134;
//const int N = 200 + 48;
const int B = 2000;
const int K = 1513;
const int MEXB = 500;
const ld eps = 1e-8;
const ld pi = acosl(-1);

mt19937 rnd(1);

int sum(int a, int b) {
    a += b;
    return (a >= M ? a - M : a);
}

int dif(int a, int b) {
    return sum(a, M - b);
}

int mul(int a, int b) {
    return a * 1ll * b % M;
}
//li mul(li a, li b) {
//    li q = (ld)a * b / M;
//    li r = a * b - q * M;
//
//    while(r < 0)
//        r += M;
//
//    while(r >= M)
//        r -= M;
//
//    return r;
////    return a * 1ll * b % M;
//}

int pow2(int n, int k) {
    if(k == 0)
        return 1;

    int pw = pow2(n, k / 2);
    pw = mul(pw, pw);

    return (k % 2 == 0 ? pw : mul(pw, n));
}

/*
*/
void solve() {
    string s;
    cin >> s;

    int m;
    cin >> m;

    string l, r;
    cin >> l >> r;

    int n = s.size();

    vector<vector<int>> pos(10);
    for(int i = 0; i < n; i++) {
        pos[s[i] - '0'].push_back(i);
    }

//    for(int i = 0; i < 10; )

    int cur = -1;
    for(int i = 0; i < m; i++) {
        int res = -1;
        for(int x = l[i] - '0'; x <= r[i] - '0'; x++) {
            auto it = upper_bound(pos[x].begin(), pos[x].end(), cur);
            if(it == pos[x].end())
                res = n;
            else
                res = max(res, *it);
        }
        cur = res;
    }

    cout << (cur < n ? "NO" : "YES") << endl;
}


int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}
/*
*/