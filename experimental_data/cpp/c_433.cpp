/*  Made by

    Akylbek Aitkali */

#include <cstring>

#include <vector>

#include <list>

#include <map>

#include <set>

#include <deque>

#include <stack>

#include <bitset>

#include <algorithm>

#include <functional>

#include <numeric>

#include <utility>

#include <sstream>

#include <iostream>

#include <iomanip>

#include <cstdio>

#include <cmath>

#include <queue>

#include <cstdlib>

#include <ctime>

#include <cassert>



#define pii pair<int, int>



#define f first

#define s second



#define pb push_back



#define mp make_pair



using namespace std;



typedef unsigned long long ull;

typedef long long ll;

typedef long double ld;



const int N = 1e5 + 30;

const int TMXN = 1e5 * 8 + 1;

const int INF = 1e9 + 7;

const ll INFL = 1e18;



int n, m;

int a[N];

ll ans, res = INFL;

int cur;

vector <int> v[N];



int main() {

    scanf("%d%d", &n, &m);

    for (int i = 1; i <= m; i++) {

        scanf("%d", &a[i]);

    }

    for (int i = 1; i <= m; i++) {

        if (i + 1 <= m && a[i + 1] != a[i]) {

            v[a[i]].pb(a[i + 1]);

        }

        if (i - 1 > 0 && a[i - 1] != a[i]) {

            v[a[i]].pb(a[i - 1]);

        }

        if (a[i - 1] > 0) {

            ans += abs(a[i] - a[i - 1]) * 1LL;

        }

    }

    for (int i = 1; i <= n; i++) {

        sort (v[i].begin(), v[i].end());

        ll x = 0;

        ll y = 0;

        if (v[i].size() > 0) {

            cur = v[i][v[i].size() / 2];

        }

        for (int j = 0; j < v[i].size(); j++) {

            x += abs(cur - v[i][j]) * 1LL;

            y += abs(i - v[i][j]) * 1LL;

        }

        res = min(res, ans - y + x);

    }

    cout << res;

    return 0;

}