#include<bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

typedef long long ll;
#define int ll

using namespace std;

const int mod = 998244353;
int bpow(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b%2)
            res = res*a%mod;
        a = a*a%mod;
        b/=2;
    }
    return res;
}
const int N = 2e6+100;
int fact[N];
int rfact[N];

int rev(int p)
{
    return bpow(p, mod-2);
}

int cnk(int n, int k)
{
    return fact[n] * rfact[k] % mod * rfact[n-k] % mod;
}

void solve()
{
    int l, n;
    cin>>l>>n;
    int ans = 0;
    for (int i=0; i<=l-2*n; i+=2)
    {
        int balls = cnk(i/2 + n - 1, n - 1);
        int tot = cnk(l - i - 2*n + n, n);
        ans = (ans + balls * tot) % mod;
//        cout<<ans<<"\n";
    }
    int all = cnk(l, 2*n);
//    cout<<ans<<" / "<<all<<"\n";
    ans = (all - ans + mod) % mod;
    cout<<2*ans%mod<<"\n";
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fact[0] = 1;
    for (int i=1; i<N; i++)
        fact[i] = i*fact[i-1]%mod;
    rfact[N-1] = rev(fact[N-1]);
    for (int i=N-2; i>=0; i--)
        rfact[i] = rfact[i+1]*(i+1)%mod;

    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
}