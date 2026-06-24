#include <bits/stdc++.h> 

#ifdef PK
#include <debug.hpp>
#else
#define debug(...)
#endif
 
using namespace std;
 
#define all(a) (a).begin(), (a).end()
#define int long long

int32_t main() {
    cin.tie(0); ios_base::sync_with_stdio(false);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string s; cin >> s;
        int c = 0;
        for (auto i: s) {
            if (i == 'U')
                c++;
        }
        if (c % 2)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}