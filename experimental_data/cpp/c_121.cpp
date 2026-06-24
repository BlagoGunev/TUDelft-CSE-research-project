//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string>
#include <iomanip>
#include <complex>
#include <math.h>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <bitset>
#include <list>

using namespace std;

#define x first
#define y second
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) int((a).size())
#define sqr(x) ((x)*(x))
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define NAME "defence"
#define FREOPEN freopen(NAME".in", "r", stdin); freopen(NAME".out", "w", stdout);
#define Freopen freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgashqt
#define free afdshjioeyqtw
#define next qpowityqwopqw

typedef unsigned int unt;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair < int, int > pii;
typedef pair < ll, ll > pll;

const ll MOD = 1e9 + 7;
const int INF = 1e9 + 1;
const ll INF64 = 1e18;
const int N = 100010;
const int M = 16;

ll n, k, p[M], a[M], nn, ans;
bool mark[M];
set < ll > s;

void rec(ll x) {
    if (x > INF)
        return;
    if (x > 0)
        s.insert(x);
    if (x > 0 && x <= n - nn)
        ans++;
    rec(x * 10 + 4);
    rec(x * 10 + 7);
}

int main() {
    //FREOPEN;
    //ios::sync_with_stdio(0);
    cin >> n >> k;
    p[1] = 1;
    for (ll i = 2; i <= 15; i++)
        p[i] = p[i - 1] * i;
    if (n <= 15 && p[n] < k) {
        cout << -1;
        return 0;
    }
    nn = min(15LL, n);
    for (int i = 1; i <= nn; i++) {
        int q = nn - i + 1;
        for (int j = nn; j >= 1; j--)
            if (!mark[j]) {
                q--;
                if (p[nn - i] * q < k) {
                    a[i] = j;
                    k -= p[nn - i] * q;
                    mark[j] = 1;
                    break;
                }
            }
    }
    rec(0);
    for (int i = 1; i <= nn; i++) {
        a[i] += n - nn;
        if (s.count(i + n - nn) && s.count(a[i]))
            ans++;
        //cout << a[i] << ' ';
    }
    cout << ans;
    return 0;
}




/*



*/