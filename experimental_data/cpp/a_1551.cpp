#include <bits/stdc++.h>

#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define ll long long int
#define inputtext freopen("input.txt", "r", stdin);
#define outputtext freopen("output.txt", "w", stdout);

using namespace std;


ll power(ll a, ll b , ll m){
    a %= m;
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

ll modInv(ll a , ll m ){
    if (m == 1)
        return 0;
    ll m0 = m, x = 1, y = 0;

    while (a > 1)
    {
        ll q = a / m, t = m;
        m = a % m;
        a = t;
        t = y;
        y = x - q * y;
        x = t;
    }

    if (x < 0)
        x += m0;
    return x;
}

ll primeFactors(ll n)
{
    ll p_fac = 0;
    while (n % 2 == 0)
    {
        p_fac++;
        n = n / 2;
    }

    
    for (ll i = 3; i * i <= n; i = i + 2)
    {
        
        while (n % i == 0)
        {
            p_fac++;
            n = n / i;
        }
    }

    
    if (n > 2)
        p_fac++;
    return p_fac;
}


void solve()
{
    int n;
    cin >> n;
    if (n % 3 == 0) {
        cout << n / 3 << " " << n / 3 << "\n";
        return;
    }
    int a = n / 3, b = (n / 3) + 1;
    if (a + (2 * b) == n) {
        cout << a << " " << b << "\n";
        return;
    }
    cout << b << " " << a << "\n";
}



int main()
{
    IOS
    #ifndef ONLINE_JUDGE
    inputtext
    outputtext
    #endif    
    
    int t;
    // int t = 1;
    cin >> t;

    while (t--)
    {        
        solve();
    }
    
    #ifndef ONLINE_JUDGE
        cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    #endif

    return 0;
}