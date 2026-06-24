#ifdef AVEVAD
#define _GLIBCXX_DEBUG
#else
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#endif

#include <bits/stdc++.h>

#define LC(V) ((V)*2+1)
#define RC(V) ((V)*2+2)
#define RT(X) sqrt(ld(X))
#define SQ(X) ((X)*(X))

using namespace std;
using ll = long long;
using ld = long double;


int main() {
#ifndef AVEVAD
    cin.tie(0);
    ios_base::sync_with_stdio(0);
#endif
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        string s;
        cin >> s;
        if (s[0] != '1' || s.back() != '1' || count(s.begin(), s.end(), '0') % 2) {
            cout << "NO\n";
            continue;
        }
        ll c1 = count(s.begin(), s.end(), '1');
        string a(n, ' '), b(n, ' ');
        for (ll i = 0, c = 0; c < c1 / 2; i++) if (s[i] == '1') a[i] = b[i] = '(', c++;
        for (ll i = n - 1, c = 0; c < c1 / 2; i--) if (s[i] == '1') a[i] = b[i] = ')', c++;
        for (ll i = 0, c = 0; i < n; i++) {
            if (s[i] == '0') a[i] = ')', b[i] = '(', c++;
            if (c % 2) swap(a[i], b[i]);
        }
        cout << "YES\n";
        cout << a << '\n';
        cout << b << '\n';
    }

}