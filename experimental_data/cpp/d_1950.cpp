#include <map>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <cassert>
#include <numeric>

using namespace std;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ckmin(a, b) a = min(a, b)
#define ckmax(a, b) a = max(a, b)
#define ld long double
#define pii pair<int, int>
#define fi first
#define se second
#define sz(a) (int)a.size()
#define int long long

const int N = 1e5 + 100;
bool dv[N], cn[N];

bool dvo(int n){
    while(n != 0){
        if(n % 10 > 1)
            return false;
        n /= 10;
    }
    return true;
}
signed main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    for(int i = 1; i < N; ++i) {
        dv[i] = dvo(i);
    }
    cn[1] = true;
    for(int i = 2; i < N; ++i){
        cn[i] = dv[i];
        for(int j = 2; j * j <= i; ++j){
            if(i % j == 0)
                cn[i] = cn[i] || (cn[i / j] && dv[j]);
        }
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if(cn[n])
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}