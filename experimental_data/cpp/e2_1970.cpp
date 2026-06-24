#include<bits/stdc++.h>
using namespace std;
const int sz = 2e5 + 5, mod = 1e9 + 7;
int s[sz], l[sz], n, m;
#define MODMATEXPO mod

#define ll long long
template<typename intex, int N>
struct matrix {
    intex x[N + 1][N + 1];
    
    matrix(intex v = 0) {
        memset(x, 0, sizeof x);
        for (int i = 1; i <= N; i++) {
            x[i][i] = v;
        }
    }

    intex * operator [] (int a) {return x[a];}

    inline matrix operator*(const matrix &r) {
        matrix<intex, N> p(0);
        for (int k = 1; k <= N; ++k) {
            for (int i = 1; i <= N; ++i) {
                if (x[i][k] == 0) continue;
                for (int j = 1; j <= N; ++j) {
                    p.x[i][j] += 1LL * x[i][k] * r.x[k][j] % mod;

#ifdef MODMATEXPO
                    p.x[i][j] %= MODMATEXPO;
#endif
                }
            }
        }
        return p;
    }
    inline matrix pow(ll p) {
        matrix r(1), a = *this;
        for (; p > 0 ; p >>= 1) {
            if (p & 1) r = r * a;
            a = a * a;
        }
        return r;
    }
    void print() {
        cout << N << '\n';
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++)
                cout << x[i][j] << " \n"[j == N];
        }
    }
};

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n;
    for(int i = 1; i <= m; i++) cin >> s[i];
    for(int i = 1; i <= m; i++) cin >> l[i];
    matrix<int, 102>mat;
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= m; j++) {
            ll a = s[i] * (s[j] + l[j]) + l[i] * s[j];
            a %= mod;
            mat.x[i][j] = a;
        }
    }
    mat = mat.pow(n);
    ll ans = 0; 
    for(int j = 1; j <= m; j++) {
        ans += mat.x[1][j];
    }
    cout << ans % mod << "\n";
    return 0;
}