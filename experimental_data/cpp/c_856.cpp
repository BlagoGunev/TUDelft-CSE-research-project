#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define ford(i, n) for (int i = ((int)(n) - 1); i >= 0; --i)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<char> vc;
typedef pair<int, int> pii;
typedef vector<pii> vii;
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()

const int mod_ans = 998244353;
const int mod_sum = 11;
void add (int &a, int b, int mod)
{
    a += b;
    if (a >= mod)
        a -= mod;
}
void sub (int &a, int b, int mod)
{
    a -= b;
    if (a < 0)
        a += mod;
}
int mult (int a, int b, int mod)
{
    return (ll)a * b % mod;
}

void solve (int n)
{
    vi a(n);

    forn (i, n)
        cin >> a[i];

    vi fact(n + 1, 1), ifact(n + 1, 1), inv(n + 1, 1);
    forn (i, sz(fact)) if (i >= 2)
    {
        const int mod = mod_ans;
        inv[i] = mod - mult(mod / i, inv[mod % i], mod);
        assert(mult(i, inv[i], mod) == 1);
        fact[i] = mult(fact[i - 1], i, mod);
        ifact[i] = mult(ifact[i - 1], inv[i], mod);
    }

    auto C = [&] (int from, int what) -> int
    {
        if (what < 0 || what > from)
            return 0;
        return mult(fact[from],
                    mult(ifact[what], ifact[from - what], mod_ans),
                    mod_ans);
    };

    vi par(n), sum(n);

    forn (i, n)
    {
        int x = a[i];
        while (x)
        {
            par[i] ^= 1;
            (par[i] ? add : sub)(sum[i], x % 10, mod_sum);
            x /= 10;
        }
    }

    vi cnt(2);
    forn (i, n)
        cnt[par[i]]++;

    vi ways_neg(cnt[0] + 1);
    forn (i, cnt[0] + 1)
    {
        int segs = (cnt[1] + 1) / 2;
        int other = cnt[1] + 1 - segs;

        ways_neg[i] = mult(C(i + segs - 1, segs - 1),
                        C(cnt[0] - i + other - 1, other - 1), mod_ans);
    }

    vector<vvi> dp(2);
    forn (it, 2)
    {
        vvi &curdp = dp[it];
        curdp = vvi(cnt[it] + 1, vi(mod_sum, 0));
        curdp[0][0] = 1;

        forn (pos, n) if (par[pos] == it)
        {
            ford (i, cnt[it]) forn (j, mod_sum)
            {
                int nj = j;
                add(nj, sum[pos], mod_sum);
                add(curdp[i + 1][nj], curdp[i][j], mod_ans);
            }
        }
    }

    int total = 0;
    forn (i, n)
        add(total, sum[i], mod_sum);

    if (cnt[1] == 0)
    {
        int ans = (total == 0 ? fact[n] : 0);
        cout << ans << endl;
        return;
    }

    int ans = 0;
    forn (i, cnt[0] + 1)
    {
        int j = cnt[1] / 2;
        forn (remi, mod_sum) forn (remj, mod_sum)
        {
            int last_rem = total;
            forn (it, 2)
            {
                sub(last_rem, remi, mod_sum);
                sub(last_rem, remj, mod_sum);
            }
            if (last_rem != 0)
                continue;

            int cur = dp[0][i][remi];
            cur = mult(cur, dp[1][j][remj], mod_ans);
            cur = mult(cur, ways_neg[i], mod_ans);
            forn (it, 2)
            {
                int curcnt = (it == 0 ? i : j);
                cur = mult(cur, fact[cnt[it] - curcnt], mod_ans);
                cur = mult(cur, fact[curcnt], mod_ans);
            }

            add(ans, cur, mod_ans);
        }
    }

    cout << ans << endl;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    int n;
    while (cin >> n)
        solve(n);
}