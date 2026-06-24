#include <bits/stdc++.h>
#define forn(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;

const int MAXN = 100000 + 500;
int a[MAXN + 1];
ll s[MAXN + 1];

int main() {
    //ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    if(n == 1) {
        cout << "NO\n";
        return 0;
    }
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        s[i] = s[i - 1] + a[i];
    }
    if(s[n] & 1LL) {
        cout << "NO\n";
        return 0;
    }
    ll need = s[n] / 2;
    for(int i = 1; i <= n; i++) {
        int l = 0, r = n, m;
        while(r > l + 1) {
            m = (l + r) / 2;
            if(s[m] - (m >= i ? a[i] : 0) >= need)
                r = m;
            else
                l = m;
        }
        if(s[r] - (r >= i ? a[i] : 0) == need) {
            cout << "YES\n";
            return 0;
        }
    }
    reverse(a + 1, a + 1 + n);
    for(int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + a[i];
    }
    for(int i = 1; i <= n; i++) {
        int l = 0, r = n, m;
        while(r > l + 1) {
            m = (l + r) / 2;
            if(s[m] - (m >= i ? a[i] : 0) >= need)
                r = m;
            else
                l = m;
        }
        if(s[r] - (r >= i ? a[i] : 0) == need) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}