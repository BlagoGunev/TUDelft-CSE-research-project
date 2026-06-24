#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (int)(a); i < (int)(b); i++)

struct mint{
    static constexpr int  m = 998244353;
    int x;
    mint() : x(0){}
    mint(ll x_):x((int)(x_ % m)){if (x < 0) x += m;}
    int val(){return x;}
    mint &operator+=(mint b){if ((x += b.x) >= m) x -= m; return *this;}
    mint &operator-=(mint b){if ((x -= b.x) < 0) x += m; return *this;}
    mint &operator*=(mint b){x= (int)((ll)(x) * b.x % m); return *this;}
    friend mint operator+(mint a, mint b){return a += b;}
    friend mint operator-(mint a, mint b){return a -= b;}
    friend mint operator*(mint a, mint b){return a *= b;}
};


void solve(){
    int N;
    cin >> N;
    vector<ll> A(N);
    ll S = 0;
    rep(i, 0, N) cin >> A[i], S += A[i];
    A.insert(A.begin(), -S);
    A.push_back(-S);
    N += 2;
    vector<ll> B(N + 1);
    rep(i, 0, N) B[i + 1] = B[i] + A[i];
    vector<mint> dp(N + 1);
    dp[0] = 1;
    int l = 0, m = 1;
    struct F {
        ll L = (1ll << 55);
        ll R = -(1ll << 55);
    };
    auto add = [&](F &a, ll b) -> void {
        a.L = min(a.L, b);
        a.R = max(a.R, b);
    };
    auto ch = [&](F a) -> int {
        return a.R - a.L <= S;
    };
    auto merge = [&](F &a, F &b) -> F {
        return {min(a.L, b.L), max(a.R, b.R)};
    };
    vector<F> base(N + 1);
    vector<mint> dp_const(N + 2);
    vector<mint> dp_L(N + 2);
    vector<mint> dp_R(N + 2);
    auto add_vec = [&](int l, int r, mint a, vector<mint> &v) -> void {
        v[l] += a;
        v[r] -= a;
    };
    while (m != N + 1){
        base[m - 1] = {B[m - 1], B[m - 1]};
        int r = m;
        while (r != N + 1){
            base[r] = base[r - 1];
            add(base[r], B[r]);
            if (!ch(base[r])) break;
            r++;
        }
        F val = {B[m], B[m]};
        int ind_ok = r;
        int ind_upper = m;
        int ind_lower = m;
        for (int L = m - 1; L >= l; L--){
            add(val, B[L]);
            if (!ch(val)) break;
            while (!ch(merge(val, base[ind_ok - 1]))) ind_ok--;
            ind_lower = min(ind_lower, ind_ok);
            ind_upper = min(ind_upper, ind_ok);
            while (ind_upper < ind_ok && base[ind_upper].R <= val.R) ind_upper++;
            while (ind_lower < ind_ok && base[ind_lower].L >= val.L) ind_lower++;
            add_vec(m, min(ind_upper, ind_lower), dp[L] * (S - val.R + val.L + 1), dp_const);
            if (ind_lower <= ind_upper){
                add_vec(ind_lower, ind_upper, dp[L] * (S - val.R + 1), dp_const);
                add_vec(ind_lower, ind_upper, dp[L], dp_L);
            }
            else{
                add_vec(ind_upper, ind_lower, dp[L] * (S + val.L + 1), dp_const);
                add_vec(ind_upper, ind_lower, dp[L] * (-1), dp_R);
            }
            int ma = max(ind_lower, ind_upper);
            add_vec(ma, ind_ok, dp[L] * (S + 1), dp_const);
            add_vec(ma, ind_ok, dp[L], dp_L);
            add_vec(ma, ind_ok, dp[L] * (-1), dp_R);
        }
        rep(i, m, r){
            dp_const[i + 1] += dp_const[i];
            dp_L[i + 1] += dp_L[i];
            dp_R[i + 1] += dp_R[i];
            dp[i] = dp_const[i] + dp_L[i] * base[i].L + dp_R[i] * base[i].R;
        }
        l = m;
        m = r;
    }
    cout << dp.back().val() << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
}