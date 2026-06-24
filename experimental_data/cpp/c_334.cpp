#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <utility>
#include <numeric>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <climits>

#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define SZ(v) ((int)(v).size())
#define FOR(i, a, b) for (typeof(a) i = (a); i < (b); ++i)
#define FORD(i, a, b) for(typeof(a) i = (a);i >= (b); --i)
#define FOREACH(iter, v) for (typeof((v).begin()) iter = (v).begin(); iter != (v).end(); ++iter)
#define REP(i, n) FOR(i, 0, n)

typedef long long ll;

using namespace std;

int main()
{
    ll n;
    cin >> n;
    ll ans = 0;
    for (ll coin = 1; coin <= 3 * n; coin *= 3) {
        ll r = n % coin, need = n / coin;
        if (r) {
            need++;
            ans = max(ans, need);
        }
    }
    cout << ans << endl;

    return 0;
}