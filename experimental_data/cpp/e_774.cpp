#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vector<int> > vvi;
typedef vector<ll> vl;
typedef vector<vector<ll> > vvl;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define forv(i, v) forn(i, v.size())
#define all(v) v.begin(), v.end()
#define mp make_pair
#define pb push_back


int main() {
    string s;
    ll m;
    cin >> s;
    cin >> m;
    int n = s.size();
    s += s;
    forn(i, 2 * n) s[i] -= '0';
    ll p = 1;
    forn(i, n - 1) {
        p = p * 10 % m;
    }
    //cout << p << endl;
    ll x = 0;
    forn(i, n) {
        x = (x * 10 + s[i]) % m;
    }
    ll res = x;
    forn(i, n) {
        x = (x - s[i] * p % m + m) % m;
        x = (x * 10 + s[i + n]) % m;
        if (s[i + 1] != 0) {
            res = min(res, x);
        }
    }
    cout << res;
}