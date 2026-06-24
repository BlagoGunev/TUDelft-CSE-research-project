#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <cstring>
#include <cctype>
#include <ctime>
#include <climits>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <tuple>
#include <bitset>
#include <cmath>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <numeric>

using namespace std;

//#define int long long

#ifndef M_PI
    #define M_PI 3.141592653589793238462643383279
#endif

#define mp make_pair
#define mt make_tuple
#define fr first
#define sc second
#define pb push_back
#define pp pop_back
#define all(x) x.begin(), x.end()
#define get0 get<0>
#define get1 get<1>
#define get2 get<2>

typedef long long ll;
typedef long double ld;
typedef tuple<long long, long long, long long> tlll;
typedef tuple<int, int, int> tiii;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
const int SZ = 2e5 + 100;
vector<pii> g[SZ];
bool e[SZ];
int d[SZ];
vector<int> res;

void euler(int v) {
    vector<int> st;
    st.push_back(v);
    while (st.size()) {
        int u = st.back();
        if (d[u] == 0) {
            res.push_back(u);
            st.pop_back();
        } else {
            while (e[g[u].back().sc])
                g[u].pop_back();
            auto pr = g[u].back();
            --d[u];
            --d[pr.fr];
            e[pr.sc] = 1;
            st.push_back(pr.fr);
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> b(n), c(n), all;
    for (int i = 0; i < n - 1; ++i) {
        cin >> b[i];
        all.push_back(b[i]);
    }
    for (int i = 0; i < n - 1; ++i) {
        cin >> c[i];
        all.push_back(c[i]);
    }
    sort(all.begin(), all.end());
    auto it = unique(all.begin(), all.end());
    vector<int> a(all.begin(), it);
    for (int i = 0; i < n - 1; ++i) {
        if (b[i] > c[i]) {
            cout << -1; return 0;
        }
        int v1 = lower_bound(a.begin(), a.end(), b[i]) - a.begin();
        int v2 = lower_bound(a.begin(), a.end(), c[i]) - a.begin();
        g[v1].push_back(mp(v2, i));
        g[v2].push_back(mp(v1, i));
    }
    int cnt = 0;
    for (int i = 0; i < 2 * n; ++i) {
        if (g[i].size() % 2)
            ++cnt;
        d[i] = g[i].size();
    }
    if (!(cnt == 0 || cnt == 2)) {
        cout << -1; return 0;
    }
    if (cnt == 2) {
        for (int i = 0; i < 2 * n; ++i) {
            if (g[i].size() % 2) {
                euler(i);
                break;
            }
        }
    } else {
        euler(0);
    }
    if (res.size() != n) {
        cout << -1; return 0;
    }
    for (int i : res)
        cout << a[i] << ' ';
    cout << endl;
    return 0;
}