#include <bits/stdc++.h>


#define pb push_back
#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define uint unsigned int

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
//    freopen("10", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ll a, b;
    cin >> a >> b;
    if (b > a) swap(a, b);
    ll s = a + b;
    vector <pair<ll, ll>> aa, bb;
    for (ll i = (ll) sqrt(a); i > 0;i--)
        if (a % i == 0)
            aa.pb({a / i, i});
    for (ll i = (ll) sqrt(b); i > 0;i--)
        if (b % i == 0)
            bb.pb({b / i, i});
    for (ll i = (ll) sqrt(s);;i--)
    {
        if (s % i == 0)
            {
                ll c = s / i;
                for (int j = 0; j < aa.size(); j++)
                {
                    ll q = aa[j].ff, w = aa[j].ss;
                    if (c >= q && i >= w) {cout << (i + c) * 2; exit(0);}
                }
                for (int j = 0; j < bb.size(); j++)
                {
                    ll q = bb[j].ff, w = bb[j].ss;
                    if (c >= q && i >= w) {cout << (i + c) * 2; exit(0);}
                }
            }
    }
    return 0;
}