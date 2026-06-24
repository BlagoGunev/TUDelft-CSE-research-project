#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define fu(i,a,b) for(int i=a;i<=b;i++)
#define nfor(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i, l, r) for (int i = int(l); i < int(r); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(x, y) make_pair((x), (y))
#define x first
#define y second
using namespace std;

typedef long long ll;
const int maxxx = 15;

ll f[maxxx][2][2];
vector<int> x, z;
int n, m;
ll a, b;

void chuanbi(int m) {
    fu(i,0,maxxx-1) f[i][0][0] = f[i][1][0] = f[i][0][1] = f[i][1][1]= -1;
    x.clear();
    int k = m % 4;
    for(int i = 0; i <= m; ++i)
        if ((i >> k) & 1 == 1) x.push_back(i);
}

void lamviecz(ll a) {
    z.clear();
    for(int i = 0; i < maxxx; ++i) z.push_back(0);
    for(int i = maxxx - 1; i >= 0; --i) {
        z[i] = a % 16;
        a/=16;
    }
}

ll calcu(int i, int ok, int ok1) {
    if (i == maxxx) return ok1;
    if (f[i][ok][ok1] >= 0) return f[i][ok][ok1];
    ll ketqua = 0;
    if (ok == 1) {
        if ((4*(15-i) > m) && (4*(14-i) <= m)) {
            for(auto j : x) {
                if (j < z[i]) ketqua += calcu(i+1, 0, ((ok1 == 1 || j == m) ? 1 : 0));
                else
                if (j == z[i]) ketqua += calcu(i+1, 1, ((ok1 == 1 || j == m) ? 1 : 0));
            }
        }
        else {
            if (m < z[i]) {
                ketqua += m * calcu(i + 1, 0, ok1) + calcu(i + 1, 0, 1);
            }
            else {
                ketqua += calcu(i + 1, 1, ((ok1 || z[i] == m) ? 1 : 0)) + z[i] * calcu(i + 1, 0, ok1);
            }
        }
    }
    else {
        if (4*(15-i) > m && 4*(14-i) <= m)
            for(auto j : x) ketqua += calcu(i+1, 0, ((ok1 == 1 || j == m) ? 1 : 0));
        else
            ketqua += m * calcu(i + 1, 0, ok1) + calcu(i + 1, 0, 1);
    }
    f[i][ok][ok1] = ketqua;
    return ketqua;
}

ll xuli(ll a) {
    lamviecz(a);
    ll ketqua = 0;
    for(int i = 0; i < 16; ++i) {
        chuanbi(i);
        m = i;
        ketqua += calcu(0, 1, 0);
    }
    return ketqua;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        scanf("%llx %llx", &a, &b);
        cout << xuli(b) - xuli((a == 0) ? 0 : a-1) << endl;
    }
}