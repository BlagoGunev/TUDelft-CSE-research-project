#include <iostream>
#include <stdio.h>
#include <fstream>
#include <queue>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <time.h>
#include <cassert>
#include <map>
#include <set>
#include <stack>
#include <time.h>
#include <cstdlib>
#include <cstring>
#include <string.h>
#include <bitset>


//#include <unordered_map>
//#include <unordered_set>

#define llong long long int
#define pb push_back
#define mp make_pair
#define pr pair <int, int>
#define X first
#define Y second
#define endl "\n"
using namespace std;
const int MAXN = 1e5 + 7;
const int INF = 1e9 + 7;
const llong LINF = 1e18;
const llong MOD = 1e9 + 7;
//const long double EPS = 1e-18;
using namespace std;
int n;
int r[MAXN], h[MAXN];
vector<pair <llong, int> > v;
int place[MAXN];
int L[MAXN];
llong ans;
llong tree[MAXN];

inline llong getmax(int x) {
    llong res = 0;
    for (; x >= 0; x = (x & (x + 1)) - 1) {
        res = max(res, tree[x]);
    }
    return res;
}
void update (int x, llong new_val)
{
    for (; x < n; x = (x | (x+1)))
        tree[x] = max (tree[x], new_val);
}
int main() {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    double beg = clock();
#else
    //freopen("rsq.in", "r", stdin);
    //freopen("rsq.out", "w", stdout);
#endif
    //ios_base::sync_with_stdio(0);cin.tie();
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &r[i], &h[i]);
        v.pb(mp(1ll * r[i] * r[i] * h[i], i));
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        place[v[i].second] = i + 1;
        L[v[i].second] = i ;
        if (i && v[i].first == v[i - 1].first) {
            L[v[i].second] = L[v[i - 1].second];
        }
    }
    for (int i = 1; i <= n; i++) {
        llong MX = getmax(L[i]);
        MX += 1ll * r[i] * r[i] * h[i];
        
        ans = max(MX, ans);
        update(place[i], MX);
    }
    
    long double ANS = 3.14159265358979323846 * ans;
    cout << setprecision(10) << fixed << ANS;
    
    
#ifdef DEBUG
    double end = clock();
    fprintf(stderr, "\n*** Total time = %.3lf ***\n", (end - beg) / CLOCKS_PER_SEC);
#endif
    return 0;
}