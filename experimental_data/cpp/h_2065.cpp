#include <bits/stdc++.h>
using namespace std;
 
#define IloveYuki ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>

int MOD = 998244353;

struct fenw
{
    int n;
    vector<ll> ft;
    fenw(int n) : n(n), ft(n+1, 0) {}
    void upd(int i, ll d)
    {
        for (; i <= n; i+= i & -i)
        {
            ft[i] = (ft[i] + d) % MOD;
            if (ft[i] < 0)
                ft[i] += MOD;
        }
    }

    ll quer(int i)
    {
        ll s = 0;
        for (; i > 0; i -= i & -i)
        {
            s = (s + ft[i]) % MOD;
        }

        return s;
    }

    ll rq(int l, int r)
    {
        if (l > r)
            return 0;

        ll res = quer(r) - quer(l - 1);
        res %= MOD;

        if (res < 0)
            res += MOD;
        
        return res;
    }
};

int main() 
{
    IloveYuki;
 
    int t;
    cin >> t;

    vector<ll> pow2(200006, 0);
    pow2[0] = 1;

    for (int i = 1; i <= 200006; i++)
    {
        pow2[i] = (pow2[i-1] * 2) % MOD;
    }

    for (int tt = 0; tt < t; tt++)
    {
        string s;
        cin >> s;

        int n = s.size();

        fenw bita0(n), bita1(n), bitb0(n), bitb1(n);

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
            {
                bita0.upd(i + 1, pow2[i]);
                bitb0.upd(i + 1, pow2[(n - 1) - i]);
            }
            else
            {
                bita1.upd(i + 1, pow2[i]);
                bitb1.upd(i + 1, pow2[(n - 1) - i]);
            }
        }

        ll k = 0;
        ll pref0 = 0;
        ll pref1 = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
            {
                k = (k + (pref1 * pow2[(n - 1) - i]) % MOD) % MOD;
                pref0 = (pref0 + pow2[i]) % MOD;
            } 
            else 
            {
                k = (k + (pref0 * pow2[(n - 1) - i]) % MOD) % MOD;
                pref1 = (pref1 + pow2[i]) % MOD;
            }
        }

        int q;
        cin >> q;
        for (int qq = 0; qq < q; qq++)
        {
            int v;
            cin >> v;

            int pos = v - 1;

            char old = s[pos];
            char newc = (old == '0' ? '1' : '0');

            ll lold = 0;
            ll lnew = 0;

            if (old == '0')
            {
                lold = bita1.quer(pos);
                lnew = bita0.quer(pos);
            }
            else
            {
                lold = bita0.quer(pos);
                lnew = bita1.quer(pos);
            }

            ll rold = 0;
            ll rnew = 0;

            if (old == '0')
            {
                rold = bitb1.rq(pos + 2, n);
                rnew = bitb0.rq(pos+2, n);
            }
            else
            {
                rold = bitb0.rq(pos + 2, n);
                rnew = bitb1.rq(pos + 2, n);
            }

            ll factl = pow2[(n-1) - pos];
            ll factr = pow2[pos];
 
            ll d = (((lnew - lold) % MOD + MOD) % MOD * factl) % MOD;
            d = ( d + (((rnew - rold) % MOD + MOD) % MOD * factr) % MOD) % MOD;
 
            k = (k + d) % MOD;
 
            if (old == '0')
            {
                bita0.upd(pos + 1, - (ll)pow2[pos]);
                bita1.upd(pos + 1, pow2[pos]);
                bitb0.upd(pos + 1, - (ll)pow2[(n-1)-pos]);
                bitb1.upd(pos + 1, pow2[(n-1)-pos]);
            } 
            else 
            {
                bita1.upd(pos + 1, - (ll)pow2[pos]);
                bita0.upd(pos + 1, pow2[pos]);
                bitb1.upd(pos + 1, - (ll)pow2[(n-1)-pos]);
                bitb0.upd(pos + 1, pow2[(n-1)-pos]);
            }

            s[pos] = newc;
 
            ll ans = ((pow2[n] - 1) % MOD + k) % MOD;
            
            if (ans < 0) 
                ans += MOD;

            cout << ans << ' ';
        }

        cout << '\n';
    }
    
}