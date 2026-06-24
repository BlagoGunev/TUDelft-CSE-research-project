#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <utility>
#include <cassert>
#include <numeric>
#include <sstream>
using namespace std;

#define REQUIRE(cond, message) \
    do { \
        if (!(cond)) { \
            std::cerr << message << std::endl; \
            assert(false); \
        } \
    } while (false)

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define for1(i, n) for (int i = 1; i <= int(n); ++i)
#define forv(i, v) forn(i, (v).size())
#define pb push_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef vector<string> vs;
typedef long double ld;

void calc(vi& p, int n)
{
    if (n < 0) return;
    if (n == 0) {
        p[n] = 0;
        return;
    }
    if (n == 1) {
        p[0] = 1;
        p[1] = 0;
        return;
    }
    int i2 = 1;
    while ((1 << i2) <= n) ++i2;
    int r = (1 << i2) / 2;
    int l = r - 1;
    while (r <= n) {
        assert(l >= 0);
        p[r] = l;
        p[l] = r;
        --l;
        ++r;
    }
    calc(p, l);
}

void solve()
{
    int n; cin >> n;
    vi p(n + 1);
    calc(p, n);
    cout << n * ll(n + 1) << endl;
    forn(i, n + 1) {
        if (i) cout << " ";
        cout << p[i];
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}